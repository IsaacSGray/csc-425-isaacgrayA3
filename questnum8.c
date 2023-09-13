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
//QUESTION 8: 

int main(int argc, char *argv[]){
printf("hello world (pid:%d)\n", (int) getpid());
int pipefile[2];
char buffer[100];
int rc=fork(); //with  child created, consider using pipe() to the child..maybe use the wait call?
if(rc<0){
//fork failure, point and laugh!
fprintf(stderr,"fork failed, laugh and clap now.\n");
exit(1);
}
else if(rc==0){
//child created, access value here NOW
printf("We are currently in child");
close(pipefile[1]);
read(pipefile[0],buffer,sizeof(buffer));
close(pipefile[0]);
}

else{ //parent goes here, should run only after child changes num1
int rc_wait=wait(NULL);
printf("We are returned to parent");
close(pipefile[0]);
const char *message="If you are reading this, tell Doctor Mario I'm awesome";
printf("hello, I am parent of %d (rc_wait:%d) (pid:%d)\n",rc, rc_wait, (int) getpid());
}
return 0;
}
