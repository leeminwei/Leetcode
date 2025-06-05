int size = 100;
//Mystack的結構體
typedef struct {
    int* arr;
    int size;
    int top;
} MyStack;


MyStack* myStackCreate() {
    //配置stack的記憶體，其結構為Mystack的結構格式
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->arr = (int*)malloc(size*sizeof(int));
    stack->size = size;
    stack->top = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->arr[++obj->top] = x;
}

int myStackPop(MyStack* obj) {
    if(obj->top==-1)
        return -1;
    else
        return obj->arr[obj->top--];
}

int myStackTop(MyStack* obj) {
    //如果記憶體裡面還沒有資料就返回-1
    if(obj->top==-1)
        return -1;
    //如果有資料了就返回第top層的數值
    else
        return obj->arr[obj->top];
}

bool myStackEmpty(MyStack* obj) {
    if(obj->top==-1)
        return true;
    else
        return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/