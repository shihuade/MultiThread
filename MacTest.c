#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>

//http://blog.csdn.net/cxsjabcabc/article/details/7829514

#define PRINT_D(intValue)   printf(#intValue" is %d\n", (intValue));
#define PRINT_U(uintValue)   printf(#uintValue" is %lu\n", (uintValue));
#define PRINT_STR(str)      printf(#str" is %s\n", (str));
#define PRINT_S(str)      printf("%s\n", (#str));

#define FOREVER_PRINT       { while(1)    printf("...");}

#define RETURN_ERROR(func, ret, return_value)     \
if((ret) != 0)        \
{   \
perror(#func" error");  \
printf("ret is %d\n", (ret));   \
return (return_value);  \
}

void  *thread_func(void *args)  
{  
   printf("son thread end...\n");
   return NULL;  
}  

void exit_process()
{
    PRINT_S("exit_process is called...")
}

// main thread
int main(int argc, char **argv)
{ 
    pthread_t son_thread;
    int ret;  
    
   atexit(exit_process);   
   
    ret = pthread_create(&son_thread, NULL, thread_func, NULL);  
   RETURN_ERROR(pthread_create, ret, -1) 
   ret = pthread_detach(son_thread);
    RETURN_ERROR(pthread_detach, ret, -1)     

    sleep(2);
    pthread_exit(NULL);
    
    printf("[Main thread]: end...\n"); 
	return 0;
}
