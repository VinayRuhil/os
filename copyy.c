
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
void main()
{ 
 char source[10];
       char destination[10];


       int s;
       int d;
       int c=0;
       char temp[50];


       printf("Enter the name of the source file ");
       scanf("%s", source);
       printf("Enter the name of the destination file ");
       scanf("%s", destination);


       s=open(source, 0);
       if(s==-1)
       {
               printf("file open error!!!!!!");
               exit(0);
       }
       d=open(destination, 1);
       if(d==-1)
       {
               d = creat(destination, 0666);
       }
 while((c=read(s, temp, sizeof(temp))) >0)
 {
         write(d, temp, c);
 }
 close(s);
 close(d);
}