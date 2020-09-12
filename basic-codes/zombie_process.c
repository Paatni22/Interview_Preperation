// checking working of zombie process. 
// Run "top" command in parallel terminal to see 
// no of zombie proceses at realtime.
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
		//parent sleeps for 5 sec. but child immediately 
		// exits, so child entry remains in process table for 
		// 5 secs, so a zombie process created for 5 secs.
		sleep(5);  // in seconds.
		// here parent resumes and reaps off(remove) child entry
		// from process table.
	}
}

