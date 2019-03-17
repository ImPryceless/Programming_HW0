#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {//the main() class is the parent

printf( "Enter a number ");//print the statement enter a number
int n;//initialize n as a integer

scanf ("%d", &n);//scanf allows the user to imput a decimal number with the value n
extern __pid_t wait (int *__stat_loc); //this wait is for the parent to wait for the child to run their program first

if (fork() == 0) {//if statement initializing fork child...fork cmd creates a child process...if process equals zero
while(n!=1){//while n does not equal 1
printf ("%d\n", n);//print the decimal value placed in n

if(n%2==0){//if n does not have a remainder divide n by 2
n=n/2;
}

else if (n%2==1){//if n has a remainder then times n by 3 and add 1
n=(3*n)+1;
}
}

//print out the decimal value place in n
printf("%d\n", n);
}

else {
wait(NULL);//parent waiting cmd  
printf("parent waiting");//now the parent process will execute so its just a simple print statement to show the wait cmd is working
}

//this cmd ends program
return 0;
}
