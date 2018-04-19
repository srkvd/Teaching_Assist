#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>
void *fun();
int counter;
pthread_mutex_t l;
int main()
{
int i,n;
pthread_mutex_init(&l, NULL);
printf("\nEnter No.of students waiting\n");
scanf("%d",&n);
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
counter+=1;
printf("\nStudent %d Entered\n", counter);
sleep(2);
printf("\nStudent %d Exited\n", counter);
pthread_mutex_unlock(&l);
}
