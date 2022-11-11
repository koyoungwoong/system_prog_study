#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum1, sum2; /* this data is shared by the thread(s) */

void *runner(void *param); /* the thread */

int main(int argc, char *argv[])
{
pthread_t tid1, tid2; /* the thread identifier */
pthread_attr_t attr1, attr2; /* set of attributes for the thread */

if (argc != 3) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	return -1;
}

if ((atoi(argv[1]) < 0) || atoi(argv[2] < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	return -1;
}

/* get the default attributes */
pthread_attr_init(&attr1);
pthread_attr_init(&attr2);

pthread_create(&tid1,&attr1,runner,argv[1]);
pthread_create(&tid2,&attr2,runner,argv[2]);


/* now wait for the thread to exit */
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);

printf("sum = %d\n",sum1+sum2);
}

/**
 * The thread will begin control in this function
 */
void *runner(void *param) 
{
int i, upper = atoi(param);
sum = 0;

	if (upper > 0) {
		for (i = 1; i <= upper; i++)
			sum += i;
	}

	pthread_exit(0);
}

