#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


int count = 0;
#define COUNT_DONE 200
unsigned int shared_data = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;
unsigned int rc;
// Print odd numbers
void* PrintEvenNos(void *ptr)
{
     rc = pthread_mutex_lock(&mutex);
     do
     {
         if(shared_data%2 == 0)
         {
             printf("Even:%d\n",shared_data);
             shared_data++;
         }
         else
         {
             rc=pthread_mutex_unlock(&mutex);//if number is odd, do not print, release mutex
         }
     } while (shared_data <= 100);
}

// print even numbers
void* PrintOddNos(void* ptr1)
{
    rc = pthread_mutex_lock(&mutex);
    do
    {
        if(shared_data%2 != 0)
        {
            printf("odd:%d\n",shared_data);
            shared_data++;
        }
        else
        {
            rc = pthread_mutex_unlock(&mutex);//if number is even, do not print, release mutex
        }
    } while (shared_data <= 100);
}



int  main()
{
 pthread_t thread1, thread2;
 pthread_create( &thread1, NULL, &PrintEvenNos, NULL);
 pthread_create( &thread2, NULL, &PrintOddNos, NULL);
 pthread_join( thread1, NULL);
 pthread_join( thread2, NULL);
 return 0;
}