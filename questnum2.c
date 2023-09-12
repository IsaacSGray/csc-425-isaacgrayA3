//Simple program..maybe a function that adds two inputs?
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
// when piping the parent is writing into the pipe whereas the child is reading
//QUESTION 2:The parent is the only one whom writes. It appear that  in fact that the child does not open or write
//It appears to output only is a blank character from the child.
//In the fork parent is the only one with the reference to the open file, in forking, the child does not call its own open
//command 

int main(int argc, char *argv[]){
printf("hello world (pid:%d)\n", (int) getpid());
int file=open("textfile.txt",O_CREAT,O_RDWR,S_IRWXO,O_TRUNC);
int rc=fork(); //with  child created, consider using pipe() to the child..maybe use the wait call?
if(rc<0){
//fork failure, point and laugh!
fprintf(stderr,"fork failed, laugh and clap now.\n");
exit(1);
}
else if(rc==0){
//child created, access value here NOW
printf("We are currently in child");
char buffer[1024]="This text is from child";
write(file,&buffer,strlen(buffer));
//Our x, num1, is changed by child..
}

else{ //parent goes here, should run only after child changes num1
int rc_wait=wait(NULL);
printf("We are returned to parent");
char buffer[1024]="This text is from the parent";
write(file,&buffer,strlen(buffer));

printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
close(file);
}
return 0;
}
