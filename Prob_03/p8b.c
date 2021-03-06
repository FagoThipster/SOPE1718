#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// pathname of the command "ls"
// $ which ls
// /bin/ls

int main(int argc, char *argv[], char *envp[])
{
        pid_t pid;

        if(argc != 2)
        {
                printf("Usage: %s dirname\n", argv[0]);
                exit(1);
        }
        pid = fork();

        if(pid > 0) // parent
        {
                printf("My child is going to execute command\"ls -laR %s\"\n", argv[1]);
        }
        else if(pid == 0)
        {
                execl("/bin/ls", "ls", "-laR", argv[1], NULL);
        }
}
