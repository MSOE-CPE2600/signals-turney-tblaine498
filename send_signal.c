/**
 * File: send_signal.c
 * Modified by: Tyler Blaine
 * 
 * Brief summary of program:
 * Sends a SIGUSR1 signal to a specific pid with a random value. 
 * Takes in the pid value as an argument, gets a random value, 
 * sends the signal along with value
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

int main(int argc, char* argv[]) {

    // Confirm there is a second argument included
    if (argc != 2) {
        printf("Not enough arguments\n");
        exit(1);
    }
    
    // Get PID
    pid_t pid = atoi(argv[1]);

    // Get random value
    srand(time(NULL));
    int value = random();
    printf("Sending signal SIGUSR1 with value: %d\n", value);

    union sigval sig_value;
    sig_value.sival_int = value;

    // Send signal
    if (sigqueue(pid, SIGUSR1, sig_value) < 0) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}
