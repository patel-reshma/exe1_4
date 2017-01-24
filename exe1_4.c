/*******************************************************************************
// Copyright(c) <2017>, Volansys Technologies
// 
// Description:
// In this file program parent process send signal to child process
// based on signal child will display output
//    
// 
// Author       - Reshma patel
//
//*******************************************************************************
//
// Jul/19/2017, Reshma, Created ()
//
// ******************************************************************************/

#include <stdio.h>
#include <signal.h>

void handler(int mysignal)
{
    printf("handler 1 for sigterm");
}

int main()
{
    int status;
    pid_t ret;
    ret = fork();
    if(ret > 0)
    { 
        printf("I am parent with pid %d \n", getpid());
       while(1)
       {
       printf("parent \n");
       sleep(1);
       }

        //sleep(1);
       ret = wait(&status);
        printf("parent exiting");
    }
    else if(ret == 0 )
    {
        printf("i am chil with pid %d \n", getpid());
        signal(SIGTERM, handler);

        while(1)
        {
            printf("child \n");
            sleep(1);
        }
        //exit(0);
    }
    return 0;

}

