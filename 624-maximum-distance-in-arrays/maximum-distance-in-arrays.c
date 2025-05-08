typedef struct{
    int index;
    int value;
    UT_hash_handle hh;
}hash;
int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
    int min = arrays[0][0];
    int max = arrays[0][arraysColSize[0]-1];
    int result = 0;
    for(int i=1 ; i<arraysSize ; i++){
        int curmin = arrays[i][0];
        int curmax = arrays[i][arraysColSize[i] - 1];
        int distance1 = abs(curmax - min);
        int distance2 = abs(max - curmin);
        if (distance1 > result) result = distance1;
        if (distance2 > result) result = distance2;
        // 更新 minVal 和 maxVal
        if (curmin < min) min = curmin;
        if (curmax > max) max = curmax;
    }
    return result;
}
/* Time limit
    hash* map = NULL;
    hash* entry = NULL;
    for(int i=0 ; i<arraysSize ; i++){
        int index = i;
        int min = arrays[i][0];
        int max = arrays[i][arraysColSize[i]-1];
        entry = malloc(sizeof(hash));
        entry->index = index;
        entry->value = min;
        HASH_ADD_INT(map,index,entry);
        entry = malloc(sizeof(hash));
        entry->index = index;
        entry->value = max;
        HASH_ADD_INT(map,index,entry);
    }
    int max = 0;
    hash *entrymin, *entrymax; 
    for(entrymin = map ; entrymin!=NULL ; entrymin = entrymin->hh.next){
        for(entrymax = map ; entrymax!=NULL ; entrymax = entrymax->hh.next){
            if(entrymin->index!=entrymax->index){
                int len = abs(entrymax->value - entrymin->value);
                if(len>max)
                    max = len;
            }
        }
    }
    return max;
*/