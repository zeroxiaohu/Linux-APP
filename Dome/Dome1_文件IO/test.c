#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main (void)
{
    int data;
    char buff[1024];
    char buf[]={0x44,0x55};
    int fd1 ,fd2;
    buff[100]=0x88;

    fd1=open("test.txt",O_RDWR);
    if(fd1==-1)
    {
        return fd1;
    }
    printf("fd1:%d\n",fd1);
    fd2=open("test2.txt",O_RDWR);
    printf("fd2:%d\n",fd2);
    if(fd2==-1)
    {
        return fd2;
    }

    data=read(fd1,buff,sizeof(buff));
    if(data==-1)
    {
        printf("read err");  
    }
    else
    {
        printf("read OK\n");
    }

    data=write(fd2,buf,sizeof(buf));
    if(data==-1)
    {
        printf("write err");
    }
    else 
    {
        printf("write OK\n");
    }
    
    close(fd1);
    close(fd2);
    return 0;
}