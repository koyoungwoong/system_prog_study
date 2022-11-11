#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main(){

pid_t pids[4];
int pid_array[4];
int random;
int course = 0,array = 0;


for(int i = 0; i < 4 ; i++) {

srand(time(NULL));
random = (rand()%16)+5;
pids[i] = fork();

if(pids[i] < 0) {
fprintf(stderr,"Fork Failed");
return 1;
}

else if(pids[i] == 0){

sleep(random);
if(course==0){
execlp("/bin/ls","ls",NULL);
}
else if(course==1){
execlp("/bin/ps","ps",NULL);
}
else if(course==2){
execlp("/bin/cal","cal",NULL);
}
else{
execlp("/bin/df","df",NULL);
}
exit(0);
}

else{
pid_array[i]=pids[i];
course++;
}
}

while(wait(NULL)>0);

for(int i = 0; i < 4; i++){
printf("[%d PID] = %d \n",i+1,pid_array[i]);
}

return 0;
}

