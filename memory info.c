Qn 6:  Write a program to report behaviour of Linux kernel including information on configured memory, amount of free and used memory. (Memory information)


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    printf("The number of processes since the system was last booted:\n");
    system("cat /proc/stat | grep 'processes' | cut -c 11-15");


    printf("\nConfigured memory details:\n");


    printf("The total memory in Kilobytes is:\n");
    system("free –kilo | awk '/Mem:/ {print $2}'");


    printf("The used memory in Kilobytes is:\n");
    system("free –kilo | awk '/Mem:/ {print $3}'");


    printf("\nThe list of load averages for the past 1, 5, and 15 minutes:\n");
    system("cat /proc/loadavg");


    return 0;
}
