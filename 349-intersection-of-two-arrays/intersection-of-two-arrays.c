/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *array = NULL;
    int size = 0;
    int number = 0;
    for(int i = 0 ; i<nums1Size ; i++){
        for(int j = 0 ; j<nums2Size ; j++){
            if(nums1[i] == nums2[j]){
                array = (int*)realloc( array , (size+1) * sizeof(int) );
                array[size] = nums2[j];
                size++;
                break;
            }
        }
    }
    int check = size;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ;j++){
            if (array[i] == array[j]){
                for(int k = j ; k<size-1 ; k++){
                    array[k] = array[k+1];
                }
                size--;
                j--;
            }
        }
    }
     *returnSize = size;  // 設定交集陣列的大小

    // **修正輸出格式**
    /*
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    */
    return array;
    /*
    for(int i=0;i<size;i++){
        printf("%d",array[i]);
    }
    
    return array;
    */
}