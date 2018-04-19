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
pthread_mutex_init(&l, NULL);
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, fun, NULL);
pthread_create(&thread2, NULL, fun, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
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
