#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

	pid_t pid ;
	int i;

	for(i =0 ; i < 5 ; i++){

	  pid  = fork();

	  if(pid  < 0 ){
		return -1;
	  }

	  else if(pid == 0){
		printf("Child Process [%d] Creating: %d\n", i, getpid());
	  }

	  else { //parent
		printf("Parent loop %d\n", i);
	  } 
	}


	while(wait(NULL) > 0);
	printf("Parent Process Terminated!!!!\n");


}


