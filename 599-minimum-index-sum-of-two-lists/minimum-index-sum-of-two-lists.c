/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    char* key;
    int position1;
    int position2;
    UT_hash_handle hh;
}hash;
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int min = list1Size + list2Size;
    int len = 0;
    hash* map = NULL;
    hash* entry = NULL;
    for(int i=0 ; i<list1Size ; i++){
        for(int j=0 ; j<list2Size ; j++){
            if(strcmp(list1[i],list2[j])==0){
                HASH_FIND_STR(map, list1[i], entry);
                if (entry == NULL) {
                    entry = malloc(sizeof(hash));
                    entry->key = list1[i];
                    entry->position1 = i;
                    entry->position2 = j;
                    HASH_ADD_KEYPTR(hh, map, entry->key, strlen(entry->key), entry);
                    len = i+j;
                    if(len<min){
                        min = len;
                    }
                }
            }
        }
    }
    char** arr = malloc(list1Size * sizeof(char*));
    int index = 0;
    for(entry = map ; entry!=NULL ; entry = entry->hh.next){
        if(entry->position2 + entry->position1 == min){
            arr[index] = malloc(strlen(list1[entry->position1]) + 1);
            strcpy(arr[index], list1[entry->position1]);
            index++;
        }
    }
    *returnSize = index;
    return arr;
}