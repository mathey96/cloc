#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>

long long current_time_millis();
void* current_tick(void* );
