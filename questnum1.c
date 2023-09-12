//Simple program..maybe a function that adds two inputs?
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
// when piping the parent is writing into the pipe whereas the child is reading
//QUESTION 1: The child can access the variable from ts parent and modify it, but the parent is unable to 
//Retrieve the new value from the child, but rather resuming from the context of where num1=47

int main(int argc, char *argv[]){
int num1;	
int num2;
int sum;
//  I want this saved in a heap..malloc the array?
//num 1 is x, parent set its to user input later
num1=47;
num2=50;
//add scanf here later
printf("hello world (pid:%d)\n", (int) getpid());

int rc=fork(); //with  child created, consider using pipe() to the child..maybe use the wait call?

if(rc<0){
//fork failure, point and laugh!
fprintf(stderr,"fork failed, laugh and clap now.\n");
exit(1);
}
else if(rc==0){
//child created, access value here NOW
printf("We are currently in child");
printf("Accessing current value of num1:%d",num1);
num1=100; //modify num1..idk if it'll pass yet
printf("New value of num1 is now:%d",num1);
//Our x, num1, is changed by child..
}

else{ //parent goes here, should run only after child changes num1
int rc_wait=wait(NULL);
printf("We are returned to parent");
printf("The current value of num1 is:%d",num1); //num 1 should be a 100..?
printf("Changing num1 to:50");
//x is accessed and changed by parent too.
num1=50;
sum=num1+num2;
printf("%d+%d=%d",num1,num2,sum);
printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
}
return 0;
}
