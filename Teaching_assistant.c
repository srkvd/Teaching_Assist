#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>
void *fun();
void ta_process();
void thr_d();
int counter = 0;
pthread_mutex_t l;
int n,s;
int main()
{
	int r;
	pthread_mutex_init(&l, NULL);
	printf("\n\t\t\t\tWelcome to Teaching Assistant of ECE department\n");
	printf("\nCheck wheather the Teaching Assistant is Busy or Free\n");
	printf("\nEnter 1 if TA is Busy and 0 if not\n");
	scanf("%d", &s);
	ta_process();
	printf("\nThe Teaching assistant is free now\n");
	printf("\nAny student having query can proceed\n");
	printf("\nEnter 1 if any student wants to go and 0 if not\n");
	scanf("%d", &r);
	switch(r)
	{
		case 1:
			{
				s=0;
				counter=0;
				ta_process();
				break;
			}
		case 0:
			{
				break;
			}
	}
}
void ta_process()
{
	printf("\nEnter No.of students waiting\n");
	scanf("%d",&n);
	switch(s)
	{
		case 1:
		{
			counter++;
			printf("\nPlease Wait outside\n");
            sleep(2);
            printf("\nStudent %d Exited\n", counter);
            printf("\nStudents waiting can go one by one\n");
            sleep(2);
			thr_d();
			break;
		}
		case 0:
		{
			printf("\nOnly one student is allowed once,Go one by one\n");
			sleep(2);
			thr_d();
	        break;
		}
	}
}
void thr_d()
{
	int i;
	for(i=0;i<n;i++)
    {
		    pthread_t thread[i];
        pthread_create(&thread[i], NULL, fun, NULL);
        pthread_join(thread[i], NULL);
	  }
}
void *fun()
{
pthread_mutex_lock(&l);
counter= counter+1;
printf("\nStudent %d Entered\n", counter);
sleep(2);
printf("\nStudent %d Exited\n", counter);
sleep(1);
pthread_mutex_unlock(&l);
}
