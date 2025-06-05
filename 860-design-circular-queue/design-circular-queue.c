


typedef struct {
    int* arr;
    int front; //代表陣列的頭
    int rear;  //代表下次要插入的位置
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    queue->arr = malloc((k+1)*sizeof(int)); //多配置一個空間是為了區分"滿"跟"空"
    queue->front = 0;
    queue->rear = 0;
    queue->k = k;
    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    //如果陣列滿了就不能做enQueue
    if((obj->rear+1)%(obj->k+1)==obj->front)
        return false;
    else{
        obj->arr[obj->rear] = value;
        obj->rear = (obj->rear + 1) % (obj->k+1);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return false;
    else{
        obj->front = (obj->front + 1) % (obj->k+1);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return -1;
    else
        return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return -1;
    else
        return obj->arr[(obj->rear-1+(obj->k+1))%(obj->k+1)];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->front == obj->rear)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->rear+1)%(obj->k+1)==obj->front)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/