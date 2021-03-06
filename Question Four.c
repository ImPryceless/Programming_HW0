#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

// Initialize global variables
unsigned long long seq[1000000] = {-1};
int last;

void *fibonacci_thread(void *vargp) {
    // Set the initial values
    seq[0] = 0;
    seq[1] = 1;

    // Calculate each Fibonacci number up to the requested one
    for (int i = 2; i <= last; i++) {
        seq[i] = seq[i - 1] + seq[i - 2]; // Set value to array
    }

    pthread_exit(0);
}

int main(int argc, char* argv[]) {

    // Convert input to int
    last = atoi(argv[1]);

    // Start calculation in a new thread
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, fibonacci_thread, NULL);
    pthread_join(thread_id, NULL);
    
    // Print results
    for (int i = 0; i <= last; i++) {
        printf("%lld\n", seq[i]);
    }

    return 0;
}
