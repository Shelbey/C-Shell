#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include <stdarg.h>

int main(){
    pid_t id;
    int fd[2];
    pipe(fd);
    char* buff="I am Hassaan";
    printf("%s",buff);
    char* reader1,*reader2,*reader3;
    // close(fd[0]);
    write(fd[1],buff,14);
    if(!fork()){
        close(fd[1]);
        int bytes=read(fd[0],reader1,15);
        // reader1[bytes-1]="/0";
        printf("%s\n",reader1);
    }
    else{
        if(!fork()){
            close(fd[1]);
            int bytes=read(fd[0],reader2,15);
            // reader2[bytes-1]="\0";
            printf("%s\n",reader2);
        }
        wait(NULL);
    }
}