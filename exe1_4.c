//*******************************************************************************
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

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sig_handler(int signo)
{
    if (signo == SIGINT)
        printf("received SIGINT\n");
}

int main()
{
    pid_t ret;
    pid_t ch,par;
    int i,status;
    if ( ( ret = fork() ) > 0) {
            printf("parent:\n");
            printf("hello:%d \n",ret);
            printf("%d \n",getpid());
            sleep(1);
           // kill(ret, SIGINT);
            ret = wait( &status);
            printf("%d \n", ret);
    }
    else {
        printf("child\n");
       //ch = getpid();
        if (signal(SIGINT, sig_handler) == SIG_ERR) {
            printf("\ncan't catch SIGINT\n");
        }
        while(1);
        exit(0);
    } 
    return 0;
}

