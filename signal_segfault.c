/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer, Sets a signal handler for SIGSEGV,
 *          the handler prints a message, program continues
 */

/**
 * Modified by: Tyler Blaine
 * 
 * Brief summary of modifications:
 * Added the handle_signal function to handle the SIGSEGV signal. Also registered the handle_signal
 * function to be called when there is a SIGSEGV signal.
 * 
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGSEGV - prints a message and program then continues where 
 *          it left off.
 */
void handle_signal() {
    printf("Received a signal\n");
}

int main (int argc, char* argv[]) {
    
    // Register for the signal
    signal(SIGSEGV, handle_signal);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
