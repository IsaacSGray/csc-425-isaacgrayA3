//Simple program..maybe a function that adds two inputs?
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// when piping the parent is writing into the pipe whereas the child is reading
//QUESTION 2: 

int main(int argc, char *argv[]){
//  I want this saved in a heap..malloc the array?
//num 1 is x, parent set its to user input later
//add scanf here later
printf("hello world (pid:%d)\n", (int) getpid());
int rc=fork(); //with  child created, consider using pipe() to the child..maybe use the wait call?
int file=open("textfile.text",O_CREAT,O_RDWR,S_IRWXO); //Thesse were maybe brkoen cause of lack of file header..?
if(rc<0){
//fork failure, point and laugh!
fprintf(stderr,"fork failed, laugh and clap now.\n");
exit(1);
}
else if(rc==0){
//child created, access value here NOW
printf("We are currently in child");
write(file,"I am from the child",1000000);
//Our x, num1, is changed by child..
}

else{ //parent goes here, should run only after child changes num1
int rc_wait=wait(NULL);
printf("We are returned to parent");
write(file,"I am from the parent",1000000);
printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
}
return 0;
}
