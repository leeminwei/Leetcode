/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* delete(int* arr,int len){
    int size = len;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ; j++){
            if(arr[i]==arr[j]){
                for(int k=j ; k<size-1 ; k++){
                    arr[k] = arr[k+1];
                }
                j--;
                size--;
            }
        }
    }
    return arr;
}
int deletesize(int* arr,int len){
    int size = len;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size ; j++){
            if(arr[i]==arr[j]){
                for(int k=j ; k<size-1 ; k++){
                    arr[k] = arr[k+1];
                }
                j--;
                size--;
            }
        }
    }
    return size;
}
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
    int* freq = calloc(101,sizeof(int));
    nums1 = delete(nums1,nums1Size);
    int len1 = deletesize(nums1,nums1Size);
    nums2 = delete(nums2,nums2Size);
    int len2 = deletesize(nums2,nums2Size);
    nums3 = delete(nums3,nums3Size);
    int len3 = deletesize(nums3,nums3Size);
    int* answer = malloc(100*sizeof(int));
    for(int i=0 ; i<len1 ; i++){
        freq[nums1[i]]++;
    }
    for(int i=0 ; i<len2 ; i++){
        freq[nums2[i]]++;
    }
    for(int i=0 ; i<len3 ; i++){
        freq[nums3[i]]++;
    }
    int index = 0;
    for(int i=1 ; i<=100 ; i++){
        if(freq[i]>=2){
            answer[index++] = i;
        }
    }
    *returnSize = index;
    answer = realloc(answer,index*sizeof(int));
    return answer;
}