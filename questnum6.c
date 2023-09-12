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
//QUESTION 6:waitpid() would be useful when you are running more than one program. Being able to refer a specific
//Process and its child allows more than calling wait on the CURRENT program only which may or may not have a child
//wait also has weird exceptions where parent will return quicker than its child.

int main(int argc, char *argv[]){
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
int execl(path,arg1,arg2,NULL);
}

else{ //parent goes here, should run only after child changes num1
int rc_wait=waitpid(rc);
printf("We are returned to parent");

printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
}
return 0;
}
