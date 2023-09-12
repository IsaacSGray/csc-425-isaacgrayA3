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
//QUESTION 4:I think there is so many variations of exec, due to different privileges and parameters to run different file types
//Which have varying data inputs and outputs. This gives the OS a sense of modularity and makes it easier to exec what you want
//Lighteningi the load on the programmer and user 

int main(int argc, char *argv[]){
printf("hello world (pid:%d)\n", (int) getpid());
//char *path="/bin/ls";
char *arg1="-lh";
char *arg2="/home";
int rc=fork(); //with  child created, consider using pipe() to the child..maybe use the wait call?
if(rc<0){
//fork failure, point and laugh!
fprintf(stderr,"fork failed, laugh and clap now.\n");
exit(1);
}
else if(rc==0){
//child created, access value here NOW
printf("We are currently in child");
char *path="/bin/ls";
char *arg1="-lh";
char *arg2="/home";
int execl(path,arg1,arg2,NULL);
}

else{ //parent goes here, should run only after child changes num1
int rc_wait=wait(NULL);
printf("We are returned to parent");

printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
}
return 0;
}
