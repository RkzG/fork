#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Proses P1 (Root) berjalan (PID: %d)\n", getpid());

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("Proses P2 dibuat (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        exit(0);
    }

    pid_t p3 = fork();
    if (p3 == 0) {
        printf("Proses P3 dibuat (PID: %d, Parent PID: %d)\n", getpid(), getppid());

        pid_t p4 = fork();
        if (p4 == 0) {
            printf("Proses P4 dibuat (PID: %d, Parent PID: %d)\n", getpid(), getppid());
            exit(0);
        }

        pid_t p5 = fork();
        if (p5 == 0) {
            printf("Proses P5 dibuat (PID: %d, Parent PID: %d)\n", getpid(), getppid());
            exit(0);
        }

        wait(NULL);  // Menunggu proses P4 selesai
        wait(NULL);  // Menunggu proses P5 selesai
        exit(0);
    }

    wait(NULL);  // Menunggu proses P2 selesai
    wait(NULL);  // Menunggu proses P3 selesai
    
    printf("Proses P1 selesai\n");

    return 0;
}
