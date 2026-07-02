#include <stdio.h>     // printf
#include <signal.h>    // signals
#include <unistd.h>    // sleep, getpid
#include <stdlib.h>    // exit

void handle_sigint(int sig) {
    printf("\nMonitor Service shutting down safely.\n");
    exit(0);
}

void handle_sigusr1(int sig) {
    printf("\nSystem status requested by administrator.\n");
}

void handle_sigterm(int sig) {
    printf("\nEmergency shutdown signal received.\n");
    exit(0);
}

int main() {
    // register signal handlers
    signal(SIGINT, handle_sigint);
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGTERM, handle_sigterm);

    printf("PID: %d\n", getpid());

    while (1) {
        printf("[Monitor Service] System running normally...\n");
        sleep(5);
    }

    return 0;
}
