#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>


static pthread_mutex_t mutex_ms = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond_ms = PTHREAD_COND_INITIALIZER;

static pthread_mutex_t mutex_bool = PTHREAD_MUTEX_INITIALIZER;

static int current_ms = 0;
static int current_sec = 0;
static int current_min = 0;

static bool tick_thread_on = false;

long long current_time_millis();
void* current_tick(void* arg);
int calculate_second();
int calculate_minute();
