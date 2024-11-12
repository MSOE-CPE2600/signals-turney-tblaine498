/**
 * File: recv_signal.c
 * Modified by: Tyler Blaine
 * 
 * Brief summary of program:
 * Receives a random value from a SIGUSR1 singal. Prints out the value 
 * received and waits for another signal.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGUSR1 - prints a the random value from info.
 */
void handle_signal(int signum, siginfo_t *info, void *context) {
    printf("Data: %d\n", info->si_value.sival_int);
}

int main() {

    // Create struct for signal action
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    // Register for the signal
    sigaction(SIGUSR1, &sa, NULL);

    // Wait until a signal is received
    while(1) {
        sleep(1);
    }

    return 0;
}
