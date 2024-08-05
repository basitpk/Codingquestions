
/*Run only on linux */

#include <stdio.h>
#include <signal.h>

void signal_handler(int signum) {
    printf("Received signal: %d\n", signum);
}

int main() {
    signal(SIGTSTP, signal_handler); // Register handler for SIGTSTP (Ctrl+Z)

    while (1) {
        // Do something
    }

    return 0;
}