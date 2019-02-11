#include <stdio.h>
#include <stdlib.h>

//prototype to wordcount function
//accepts pointer to char variable
//uses that char array to open a file and count the words in it
//returns nothing
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
            //printf("process id %ld as well as argv[%d]\t", forkId, i);
            countword(argv[i]);
            exit(0);
        }
    }
    int status;

    for (i=1; i < argc; i++)
    {
        wait(&status);
    }
    printf("All %d files have been counted!\n", argc-1);
    //printf("This is argc = %d\n", argc);
    //printf("argument1: %s\n", argv[1]);
    //printf("argument4: %s\n", argv[4]);

    //char *test5 = argvi[5]; //it works
    //printf("argument5: %s\n", test5);
    return 0;
}

void countword(char *fname)
{   
    FILE *f;
    int count = 0;
    char word;

    //printf("function test %s\n", fname);
    f = fopen(fname, "r");

    if (f == NULL)
    {
        printf("Failed to open file: %s\n", fname);
        return;
    }

    while ((word=getc(f)) != EOF)
    {
        if (word == ' ' || word == '\t' || word == '\n')
            count++;
    }
    printf("Child precess for %s: number of words is %d\n", fname, count);
    close(f);
}
