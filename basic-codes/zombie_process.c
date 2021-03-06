// checking working of zombie process. 
// Run "top" command in parallel terminal to see 
// no of zombie proceses at realtime.
#include<stdio.h>
#include<unistd.h>  // for fork() and sleep().
#include<stdlib.h> // for exit().
#include<sys/wait.h> // for wait(). wait() not used here.
//    wait(NULL) -> calling this in parent, will make parent to 
//                   wait for next 1 child. then resume.
int main()
{
	int id = fork();
	if(id==0)  // child
	{
		exit(0);
	}
	else     // parent
	{
		//parent sleeps for 5 sec. but child immediately 
		// exits, so child entry remains in process table for 
		// 5 secs, so a zombie process created for 5 secs.
		sleep(5);  // 5 in seconds.
		// here parent resumes and reaps off(remove) child entry
		// from process table.
	}
}

