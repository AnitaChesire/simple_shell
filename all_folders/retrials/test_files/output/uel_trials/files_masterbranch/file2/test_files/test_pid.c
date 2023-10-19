#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    /*pid_t my_pid;*/
    pid_t my_ppid;

    /*my_pid = getpid();*/
    my_ppid = getppid();

    /*printf("PID is %u\n", my_pid);*/
    printf("PPID is %u\n", my_ppid);
    return (my_ppid);
}
