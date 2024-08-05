#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Callback function type
typedef void (*Callback)(void*);

// Function to be executed asynchronously
void async_task(void* data) {
    int seconds = *(int*)data;
    printf("Asynchronous task started with delay: %d seconds\n", seconds);
    sleep(seconds); // Simulate a long-running task
    printf("Asynchronous task completed\n");
}

// Function to initiate asynchronous execution
void start_async(Callback callback, void* data) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL,  (void* (*)(void *))callback, data);
    pthread_detach(thread_id); // Detach thread to avoid blocking
}

int main() {
    int delay = 3;
    printf("Main program starting\n");

    start_async(async_task, &delay); // Start the asynchronous task

    printf("Main program continuing...\n");
    sleep(5); // Allow time for the asynchronous task to complete

    printf("Main program exiting\n");
    return 0;
}