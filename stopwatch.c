#include "stopwatch.h"
#include <stdio.h>



long long current_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long) ( (tv.tv_usec / 1000));
}

int calculate_ms(){
	long long tick = 0;
	while(1){
		if(tick != current_time_millis()){
			fprintf(stderr,"%lld \n", current_time_millis());
			current_ms = current_time_millis();
		}
	}
}

void* current_tick (void* arg){
	long long tick = 0;
	fprintf(stderr,"thread 2 executed\n");
	while(tick_thread_on == true){
		if(tick != current_time_millis()){
			pthread_mutex_lock(&mutex_ms);
			tick = current_time_millis();
			current_ms = tick;
			fprintf(stderr,"thread 2 executed\n");
			pthread_cond_signal(&cond_ms);  // Signal the condition variable
			pthread_mutex_unlock(&mutex_ms);
		}
	}
	pthread_mutex_lock(&mutex_bool);
	tick_thread_on = false;
	pthread_mutex_unlock(&mutex_bool);
	pthread_exit(NULL);
	return NULL;
}
