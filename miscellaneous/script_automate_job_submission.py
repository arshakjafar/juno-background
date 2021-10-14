### Author: Beatrice Jelmini, date: 2021/01/21
### Last update: 2021/01/25
### This script can be used to automate multiple-job submission through HTCondor

# Note: use sbp.run() for Python3; use sbp.call() for Python2

import os
import sys
import shutil
sys.path.append("/usr/lib64/python2.7/site-packages/")
import numpy as np
import numpy.random as nprand
import subprocess as sbp
import time

# global flags
verbose_mode = True
#verbose_mode =False
#submit = True
submit = False

# global absoulte paths
setup_path = "/cvmfs/juno.ihep.ac.cn/centos7_amd64_gcc830/Pre-Release/J20v2r0-Pre2/setup.sh"
tutorial_path = "/cvmfs/juno.ihep.ac.cn/centos7_amd64_gcc830/Pre-Release/J20v2r0-Pre2/offline/Examples/Tutorial/share/"



### for the user: please modify the strings in the following method to match your need
### if necessary, please modify only the name of the output files (output_file_name, user_output_file_name), and not the path
def sniper_command(x_,job_dir_,n_events_):
	# put together the sniper command with all flags and paths for root files
	
	python_script = "tut_detsim.py"
	general_options = "--no-gdml --anamgr-normal-hit --evtmax %s --seed %s" % (n_events_,str(nprand.randint(0,1000000)))
	generator_mode = "gendecay"
	generator_options = "--nuclear U-238 --volume pTarget --material LS"
	
	output_file_name = "detsim_job_%s.root" % x_ 
	output_path = job_dir_ + "/output/" + output_file_name
	output = " --output " + output_path
	user_output_file_name = "detsim_user_job_%s.root" % x_
	user_output_path = job_dir_ + "/output/" + user_output_file_name
	user_output = " --user-output " + user_output_path
	
	command = "python " + tutorial_path + python_script + " " + general_options + output + user_output + " " + generator_mode + " " + generator_options
	
	return command, output_path, user_output_path


def create_executable_file(x_,job_dir_,command_):
	# create an executable file .sh
		
	exec_name = job_dir_+'/run_sniper_job_'+x_+'.sh'
	if verbose_mode:
		print("Creating executable file %s" % exec_name)
	
	f = open(exec_name,"w")
	f.write("#!/bin/bash\n")
	f.write("export CMTCONFIG=amd64_linux26\n")
	f.write("source %s \n" % setup_path)
	f.write(command_)
	f.close()
	
	# make the file executable
	#list_files = sbp.run(['chmod','+x',exec_name])  # for Python3
	list_files = sbp.call(['chmod','+x',exec_name])  # for Python2
	
	return exec_name


def create_condor_cfg_file(x_,job_dir_,exec_name_):
	# create a THCondor submit description file
	
	config_name = job_dir_+'/condor_submit_descr_file_job_'+x_+'.sub'
	if verbose_mode:
		print("Creating condor submit description file %s " % config_name)
	
	f = open(config_name,"w")
	f.write("universe = vanilla \ngetenv = true\n")
	f.write("executable = %s \n" % exec_name_)
	f.write("log = %s/log/job_%s.log\n" % (job_dir_,x_))
	f.write("output = %s/log/job_%s.out\n" % (job_dir_,x_))
	f.write("error = %s/log/job_%s.err\n" % (job_dir_,x_))
	f.write("+MaxRuntime = 86400 \nShouldTransferFiles = YES \nWhenToTransferOutput = ON_EXIT \nqueue 1 ")
	f.close()	
	
	return config_name


def def_number_string(n_jobs_):
	# create a list of string of numbers of the form xyz, from '000' to '<n_jobs-1>'
	
	if (n_jobs_>1000):
		print("\nError: max number of jobs is 1000, use a value equal or less than 1000.")
		sys.exit(-1)
	
	n=0
	str_list=[]
	
	for i in np.arange(0,10):
		for j in np.arange(0,10):
			for k in np.arange(0,10):
				str_list.append(str(i)+str(j)+str(k))
				n = n+1
				if n == n_jobs_:
					return str_list


def main(argv):

	if (len(argv)==0):
		n_jobs = 2
		n_events = "1000"
		print("No arguments given, use of default values: %s jobs, %s events per job" % (str(n_jobs),n_events))
	elif (len(argv)==2):
		n_jobs = int(argv[0])
		n_events = argv[1]
		print("Use of given values: %s jobs, %s events per job" % (argv[0],argv[1]))
	else: 
		print("Error: wrong arguments")
		print("Usage: python test_condor.py <n_jobs> <n_events>")
		print("Example: python test_condor.py 10 1000")
		return -1

	num_string = def_number_string(n_jobs)

	# get path of current directory
	curr_dir = os.getcwd()
	print("\nPath of current working directory:")
	print(curr_dir)

	# create txt files with paths to output files with user data and EDM
	f_EDM = open(curr_dir+'/paths_to_EDM_root_files.txt',"w")
	f_user = open(curr_dir+'/paths_to_user_root_files.txt',"w")

	# create file for multiple-job submission
	f_jobs = open(curr_dir+'/submit_multiple_jobs.sh',"w")

	# loop on the number of jobs and create a directory for each job
	for x in num_string:
	
		job_dir = curr_dir + '/job_' + x
		parts = os.path.split(job_dir)
		if verbose_mode:
			print("\nCreating directory: %s" % job_dir)
		else:
			print("\nCreating %s " % parts[-1])
	
		# check if the directory already exists -> directory will be removed and the content deleted
		if (os.path.isdir(job_dir)==True):
			print("Warning: "+job_dir+" already exists: it will be removed and recreated")
			try:
				os.removedirs(job_dir)
			except OSError as e:
				if verbose_mode:
					print("Warning: %s : %s - content will be deleted" % (job_dir,e.strerror))
				shutil.rmtree(job_dir)

		# create job directory and subdirectories
		os.mkdir(job_dir)	
		os.mkdir(job_dir+'/log')
		os.mkdir(job_dir+'/output')

		# define command and its options/flags + get and save paths to root files
		command, output_path, user_output_path = sniper_command(x,job_dir,n_events)
		f_EDM.write(output_path+'\n')
		f_user.write(user_output_path+'\n')

		# create executable file
		exec_name = create_executable_file(x,job_dir,command)

		# create condor configuration file
		config_name = create_condor_cfg_file(x,job_dir,exec_name)

		# write on file for multiple-job submission
		f_jobs.write("condor_submit -name sn-01.cr.cnaf.infn.it %s \n" % config_name)

		# submit job 
		if submit:
			
			print("Submitting %s" % parts[-1])
	
			#sbp.run(['condor_submit','-name','sn-01.cr.cnaf.infn.it',config_name])  # for Python3
			#sbp.run(['echo','condor_submit','-name','sn-01.cr.cnaf.infn.it',config_name])  # for Python3
			sbp.call(['condor_submit','-name','sn-01.cr.cnaf.infn.it',config_name])  # for Python2
			sbp.call(['echo','condor_submit','-name','sn-01.cr.cnaf.infn.it',config_name])  # for Python2
			time.sleep(0.2)

	f_EDM.close()
	f_user.close()
	f_jobs.close()

	# print sniper command 
	f = open(curr_dir+"/sniper_command.txt","w")
	f.write(command)
	f.close()


if __name__=="__main__":
	argv = sys.argv[1:]
	main(argv)


