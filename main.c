#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void creating_processes(int pattern) {
    printf("Process %d (PID: %d): beginning\n", pattern, getpid());

    pid_t pid = getpid();

    int sleeping_time = rand() % 8 + 1;
    prinf("Process %d (PID: %d): will sleep for %d seconds.\n", pattern, getpid(), sleeping_time);
    sleep(sleeping_time);

    printf("Process %d (PID: %d): existing.\n", pattern, getpid())
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Number of arguments not valid.\n");
        return 1;
    }
    int subprocesses_things = atoi(argv[1]);
    int pattern_number = atoi(argv[2]);
    if (subprocesses_things < 1 || subprocesses_things > 256) {
        printf("Number of subprocesses not between 1 and 256.\n");
        return 1;
    }

    srand(time(NULL));

    if (pattern_number == 1) {
        printf("** Pattern 1: creating %d processes.\n", subprocesses_things);
        for (int i = 0; i != subprocesses_things; i++) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("Fork Failed!")
                return 1;
            } else if (pid == 0) {
                creating_processes(i);
                exit(0);
            } else {
                printf("Parent: created child %d (PID: %d)\n", i, pid)
            }
        } 
        while(wait(NULL) > 0);
        printf("** Pttern 1: All children have exited.\n");
    } else if (pattern_number == 2) {
        printf("** Pattern 2: creating %d processes.\n", subprocesses_things);
        for (int i = 0; i != subprocesses_things; i++) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("Fork Failed!")
                return 1;
            } else if pid( == 0) {
                printf("Child %d (PID: %d): starting.\n", i , getpid());
                creating_processes(i);
                exit(0);
            } else {
                printf("Parent: created child %d (PID: %d).\n", i, pid);
                wait(NULL);
            }
        }
        printf("** Pttern 1: All children have exited.\n");
    } else if (pattern_number == 3) {
        printf("This might not be worked on, try again another day.\n");
        return 1;
    } else {
        printf("Pattern Number not valid.\n");
        return 1;
    }
    return 0;
} 