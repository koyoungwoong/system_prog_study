#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

	pid_t pid_array[4];
	int i,j, status, waitpid;
	char buf[4] = "#$%&";

	for(i =0 ; i < 4 ; i++){

		pid_array[i] = fork();

	  if(pid_array[i] < 0 ){
		perror("fork error");
		return -1;
	  }

	  else if(pid_array[i] == 0){
		
		printf("Child Process [%d] Creating: %d\n", i, getpid());
		sleep(5);
		printf("Child Process [%d] Exiting: %d\n", i, getpid());
		exit(0);


	  }

	  else { //parent
		printf("Parent : for -%d \n", i);
	  } 
		
	}


	while((waitpid = wait(&status)) > 0);

	for(i=0;i<4;i++){
		printf("My Child[%d] : %d terminated\n", i, pid_array[i]);
 	}


}


