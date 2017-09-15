#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

void *printHello(void *threadId){
	int tid=*((int*)threadId);
	cout<<"Hello Runoob! thread Id is "<<tid<<endl;
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];
	int indexes[NUM_THREADS];
	int rc;
	int i;
	for(i=0;i<NUM_THREADS;i++){
		cout<<"main function : create thread  "<<i<<endl;
		indexes[i]=i;
		rc=pthread_create(&threads[i],NULL,printHello,(void*)&(indexes[i]));

		if(rc){
			cout <<"Error :can not create thread :"<<rc<<endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
