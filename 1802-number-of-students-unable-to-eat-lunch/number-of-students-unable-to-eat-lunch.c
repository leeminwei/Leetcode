int* push(int* arr,int size){
    int first = arr[0];
    for(int i=0 ; i<size-1 ; i++){
        arr[i] = arr[i+1];
    }
    arr[size-1] = first;
    return arr;
}
int* pop(int* arr , int size){
    for(int i=0 ; i<size-1 ; i++){
        arr[i] = arr[i+1];
    }
    size = size-1;
    arr = realloc(arr,(size+1)*sizeof(int));
    arr[size] = '\0';
    return arr;
}
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count = 0;
    while(studentsSize != count){
        if(students[0]==sandwiches[0]){
            students = pop(students,studentsSize);
            sandwiches = pop(sandwiches,sandwichesSize);
            studentsSize = studentsSize-1;
            sandwichesSize = sandwichesSize-1;
            count = 0;
        }
        else{
            students = push(students,studentsSize);
            count++;
        }
    }
    return studentsSize;
}