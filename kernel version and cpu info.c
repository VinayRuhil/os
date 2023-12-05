Qn 5: Write a program to report behaviour of Linux kernel including kernel version, CPU type and CPU information.


#include <stdio.h>
#include <stdlib.h>


int main() {
    system("clear");
    system("echo");
    
    printf("The CPU Model: ");
    system("cat /proc/cpuinfo | grep -m1 'model name' | cut -c 14-");


    printf("\nThe Kernel Version: ");
    system("cat /proc/sys/kernel/osrelease");


    printf("\nThe amount of time CPU has spent in user mode: ");
    system("cat /proc/stat | grep -m1 'cpu' | cut -c 15-18");


    printf("\nThe number of context switches: ");
    system("cat /proc/stat | grep 'ctxt' | cut -c 6-");


    return 0;
}
