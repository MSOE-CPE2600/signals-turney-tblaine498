/**
 * File: signal_sigaction.c
 * Modified by: Tyler Blaine
 * 
 * Brief summary of program:
 * The program waits for a SIGUSR1 signal and prints the PID
 * that sent the signal. This is done by using the sigaction
 * function to pass the pid into the handler function.
 * 
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/**
 * @brief Signal handler for SIGUSR1 - prints a message containing the PID from where 
 *          the signal was sent, program continues
 */
void handle_signal(int signum, siginfo_t *info, void *context) {
    printf("Received a signal from PID: %d\n", info->si_pid);
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
