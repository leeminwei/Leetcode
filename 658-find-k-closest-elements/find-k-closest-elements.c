/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int position;
    int distance;
    UT_hash_handle hh;
}hash;
int cmp(const void*a,const void*b){
    hash* ha = *(hash**)a;
    hash* hb = *(hash**)b;
    if (ha->distance == hb->distance) {
        // 若距離相同，照數值順序排列
        return ha->position - hb->position;
    }
    return ha->distance - hb->distance;
}
int cmpint(const void*a,const void*b){
    return *(int*)a - *(int*)b;
}
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    hash* map = NULL;
    hash* entry = NULL;
    for(int i=0 ; i<arrSize ; i++){
        int position = i;
        entry = malloc(sizeof(hash));
        entry->position = position;
        entry->distance = abs(arr[i]-x);
        HASH_ADD_INT(map,position,entry);
    }
    //依照distance排序
    int count = HASH_COUNT(map);
    hash** array = malloc(count * sizeof(hash*));
    int idx = 0;
    for (entry = map; entry != NULL; entry = entry->hh.next) {
        array[idx++] = entry;
    }
    qsort(array, count, sizeof(hash*), cmp);
    *returnSize = k;
    int* answer = malloc(k*sizeof(int));
    int index = 0;
    for(int i=0 ; i<k ; i++){
        answer[index++] = arr[array[i]->position];
    }
    qsort(answer, k, sizeof(int), cmpint);
    return answer;
}