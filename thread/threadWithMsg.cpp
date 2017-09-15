#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5
struct thread_data{
	int threadId;
	char *message;
};

void *printHello(void *threadarg){
	thread_data *mydata=(thread_data *)threadarg;

	cout<<"Hello Runoob! thread Id is "<<mydata->threadId;
	cout<<" Message is "<<mydata->message<<endl;

	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];
	thread_data datas[NUM_THREADS];
	int rc;
	int i;
	for(i=0;i<NUM_THREADS;i++){
		cout<<"main function : create thread  "<<i<<endl;
		datas[i].threadId=i;
		datas[i].message="this is a message";

		rc=pthread_create(&threads[i],NULL,printHello,(void*)&(datas[i]));

		if(rc){
			cout <<"Error :can not create thread :"<<rc<<endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
