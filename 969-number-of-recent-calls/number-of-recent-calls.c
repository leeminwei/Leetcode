

int size = 10000;
typedef struct {
    int* arr;
    int size;
    int time;
    int position;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* counter = (RecentCounter*)malloc(sizeof(RecentCounter));
    counter->arr = malloc(size*sizeof(int));
    counter->size = size;
    counter->time = 0;
    counter->position = 0;
    return counter;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->arr[obj->position++] = t; //紀錄所有request的時間(t代表時間)
    obj->time = 0;
    for(int i=0 ; i<obj->position ; i++){
        if(obj->arr[i]>=t-3000 && obj->arr[i]<=t)
            obj->time++;
    }
    return obj->time;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/