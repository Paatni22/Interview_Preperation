#include<stdio.h>
#include<unistd.h>  // for fork() and sleep().
#include<stdlib.h> // for exit().
#include<sys/wait.h> // for wait(). wait() not used here.
int main()
{
	int id = fork();
	if(id==0)
	{
		exit(0);
	}
	else
	{
		sleep(5);  // in seconds.
	}
}

