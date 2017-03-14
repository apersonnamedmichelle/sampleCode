/*
* Example of redirecting stdout to a pipe 
*
* Michelle 
* 3/3/2017
*/
#include <stdio.h>
#include <stdlib.h>	//exit
#include <sys/types.h> 	//open, getpid, wait
#include <sys/stat.h>	//open
#include <fcntl.h>	//open, dup
#include <unistd.h> 	//dup, close, fork, getpid, pipe, read, write
#include <sys/wait.h>	//wait
int main (int argc, char *argv[])
{
	int pid, status;	//for forking
	int pd[2], n = 0;	//for piping 
	char buf[1024] = "\0";

	//create pipe
	pipe(pd);	//pd[0] = read end, pd[1] = write end
	
	//create fork
	pid = fork();
	if (pid == -1){
		printf("Damn, fork didn't work\n");
	}
	if (pid) { //parent - will read from the pipe
		//parent doesn't need the write end of the pipe
		close(pd[1]);
		printf("I am the parent, pid=%d, mypid=%d\n", pid, getpid());
		
		//wait for child to die 
		pid = wait(&status);
		printf("I am the parent. Child pid=%d died, status=%d\n", pid, status);		
		
		//parent reads from the pipe and prints out what was read
		n = read(pd[0], buf, 1024);
		printf("Parent read %d bytes, buf: \"%s\"\n", n, buf);
			
		//close the read end 
		close(pd[0]);
				
	}else{ //child - will write to pipe
		//child doesn't need to read from the pipe
		close(pd[0]);
		
		//close stdout and replace with write end of pipe 
		close(1);
		dup(pd[1]);
		
		//we don't need write end of pipe
		close(pd[1]);

		//This will be sent to the pipe
		printf("I am the child, pid=%d, mypid=%d\n", pid, getpid());
		
		exit(1);
		printf("Will not see this line because of exit()\n");
	}	

	return 0;
}
