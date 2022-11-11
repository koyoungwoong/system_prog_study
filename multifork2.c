#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

	pid_t pid_array[4];
	int i,j;;

	for(i =0 ; i < 4 ; i++){

		pid_array[i] = fork();

	  if(pid_array[i] < 0 ){
		perror("fork error");
		return -1;
	  }

	  else if(pid_array[i] == 0){
		
		printf("Child Process [%d] Creating: %d\n", i, getpid());
		sleep(2);
		exit(0);

	  }

	  else { //parent
		printf("Parent loop %d\n", i);
	  } 
		
	}


	while(wait(NULL) > 0);

	for(i=0;i<4;i++){
		printf("My Child : %d \n",pid_array[i]);
 	}


}


