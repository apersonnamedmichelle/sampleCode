/*
* Simple I/O redirect sample
* Michelle
* 3/3/2017
*/
#include <stdio.h>
#include <sys/types.h>	//open
#include <sys/stat.h>	//open
#include <fcntl.h>	//open, dup
#include <unistd.h>	//close, dup
int main (int argc, char *argv[])
{
	int fout;
	int stdout_copy = dup(1);	//make a copy of stdout 
	printf("Testing IO rediction\n");
	
	//close stdout and replace with fout
	close(1);
	fout = open( "redirect.txt", O_WRONLY|O_CREAT,0644);
	
	printf("This should be in redirect.txt\n");

	//close fout and replace with stdout copy (then close stdout copy)
	close (fout);
	dup(stdout_copy);	
	close(stdout_copy);

	printf("This should be in terminal\n");
	return 0;
}
