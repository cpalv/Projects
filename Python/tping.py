#!/usr/bin/env python3
from time import strftime, sleep
from signal import SIGINT
import argparse
import os
import re

# cleanup function, wait for child process
# write the final timestamp, close files and exit
def cleanup():
	os.wait()
	f.write(strftime("Ended at %B %d, %Y %H:%M:%S\n"))
	f.close()
	exit()


# https://docs.python.org/3/library/argparse.html
parser = argparse.ArgumentParser(description="ping a host over an period of time")
parser.add_argument('-?', action='help', help="alias for -h/--help")
parser.add_argument('-t', nargs='?', metavar="minutes", type=float,  default=1,
		    help="Number of minutes to run ping for.  Can also be a percentage of a minute (ie, .05)")
parser.add_argument('-o', nargs='?', metavar="output file", type=str, default=os.sys.stdout,
		    help="Write output to file, default is standard out")
parser.add_argument('IP', nargs='?', metavar="ip address", type=str, default="127.0.0.1",
		    help="IP address to ping, defaults to localhost 127.0.0.1")
args = parser.parse_args()


# Verify user entered a valid IP address
regx = "^[1-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$"
pattern = re.compile(regx)

if re.fullmatch( pattern=pattern, string=args.IP) is None:
	print("Please enter a valid IP address")
	exit()

# 'is' keyword is an idenity test
# OrcA == OrcB, they're both Orcs
# but OrcA IS NOT OrcB
if args.o is os.sys.stdout:
	print("Writing output to stdout")
	f = os.sys.stdout # add a pointer to os.sys.stdout

else:
	try:
		f = open(args.o, 'w')

	except IOError as err:
		print("Error opening %s:%s", (args.o, err))
		exit()


path = "/usr/bin/fping"
cmd = ("fping", "-s", "-l", "-i", "10", args.IP)
timer = 60*args.t # number of seconds * user entered number of minutes ( could be a fraction )

f.write(strftime("Beginning at %B %d, %Y %H:%M:%S\n"))
f.flush() 	# Weird bug, after fork() would write the string above twice
	  		# flush file write buffer before fork()
			# STDOUT is linebuffered, flush buffer 

childpid = os.fork()
if childpid:
# parent process
	# Catch user entered interrupt and cleanup nicely	
	try:
		sleep(timer)

	except KeyboardInterrupt:
		cleanup()

	os.kill(childpid, SIGINT) # send SIGINT to child
	cleanup()


else:
# child process
	# duplicate underlying file descriptors
	# os.sys.stdout = f, did not work as expected
	# suspecion is that it only copied the IO object
	# or the pointer was lost once the exec occured
	os.dup2(f.fileno(), os.sys.stdout.fileno())
	os.dup2(f.fileno(), os.sys.stderr.fileno())
	f.close()

	try:
		os.execv(path, cmd)

	except FileNotFoundError:
		# If fping isn't available, try ping
		cmd = ("ping", args.IP)
		path = "/bin/ping"
		os.execv(path, cmd)
