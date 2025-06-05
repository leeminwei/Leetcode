int size = 100;
typedef struct {
    int* arr;
    int size;
    int top;
    int front;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->arr = (int*)malloc(size*sizeof(int));
    queue->size = size;
    queue->top = -1;
    queue->front = 0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->arr[++obj->top] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->front > obj->top)
        return -1;
    else{
        return obj->arr[obj->front++];
    }
}

int myQueuePeek(MyQueue* obj) {
    if(obj->front > obj->top)
        return -1;
    else
        return obj->arr[obj->front];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->front > obj->top)
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/