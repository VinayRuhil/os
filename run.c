#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

	pid_t pid;

	pid = fork();

	if(pid < 0){
		fprintf(stderr, "Fork Failed...\n");
		return 1;

	}
	else if(pid == 0){

		printf("Child process executing.....\n");
		printf("Child process completed its task..\n");

	}else {
		printf("Parent process waiting for the child to finish...\n");

		wait(NULL);

		printf("Parent process completed..\n");
	}
	return 0;
}

