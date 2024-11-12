/**
 * File: signal_alarm.c
 * Modified by: Tyler Blaine
 * 
 * Brief summary of program:
 * A register is set for a SIGALRM so handle_signal can get called when there is 
 * an alarm. An alarm is set for 5 seconds and the program waits so the handler
 * can "catch it" program then exits.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGALRM - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    exit(0);
}

int main() {

    // Register for the signal
    signal(SIGALRM, handle_signal);

    // Set Alarm
    alarm(5);
    printf("Alarm has been set\n");

    // Wait until a signal is received
    while(1) {
        sleep(1);
    }

    return 0;
}
