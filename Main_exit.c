#include <stdio.h>
#include <pthread.h> //多线程相关操作头文件，可移植众多平台

//using namespace std;

#define NUM_THREADS 5 //线程数

void* say_hello( void* args )
{
	int i = *( (int*)args ); //对传入的参数进行强制类型转换，由无类型指针转变为整形指针，再用*读取其指向到内容
 	 printf( "hello in %d  %d %d \n",i, *( (int*)args ), pthread_self());
	pthread_exit( 0 );
} //函数返回的是函数指针，便于后面作为参数

int main()
{
    pthread_t tids[NUM_THREADS]; //线程id
    printf("hello in main..i\n");
    for( int i = 0; i < NUM_THREADS; ++i )
    {
		int ret = pthread_create( &tids[i], NULL, say_hello, (void*)&i ); //传入到参数必须强转为void*类型，即无类型指针，&i表示取i的地址，即指向i的指针
		printf("Current pthread id = %d \n ",tids[i]);  // << endl; //用tids数组打印创建的进程id信息
		if( ret != 0 ) //创建线程成功返回0						 
    	 {
	    	printf( "pthread_create error:error_code= %d \n" ,ret); //<< endl;
		}
	}
	
	printf("before exit \n");
	pthread_exit( NULL ); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态
	printf("after exit \n");
}

