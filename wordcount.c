#include <stdio.h>
#include <stdlib.h>

void countword(char*);

int main(int argc, char *argv[])
{
    long forkId;
    int i;
    for (i=1; i < argc; i++)
    {
        if (fork() == 0)
        {
            forkId = getpid();
            printf("process id %ld as well as argv[%d] = %s\n", forkId, i, argv[i]);
            countword(argv[i]);
            exit(0);
        }
    }
    int status;

    for (i=1; i < argc; i++)
    {
        wait(&status);
    }

    //printf("This is argc = %d\n", argc);
    //printf("argument1: %s\n", argv[1]);
    //printf("argument4: %s\n", argv[4]);

    //char *test5 = argvi[5]; //it works
    //printf("argument5: %s\n", test5);
    return 0;
}

void countword(char *fname)
{   
    printf("function test %s\n", fname);
}
