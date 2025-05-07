/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int max = 0;
    if(nums1Size>nums2Size) 
        max = nums1Size;
    else 
        max = nums2Size;
    int* freq1 = calloc(1001,sizeof(int));
    int* freq2 = calloc(1001,sizeof(int));
    for(int i=0 ; i<nums1Size ; i++){
        freq1[nums1[i]]++;
    }
    for(int i=0 ; i<nums2Size ; i++){
        freq2[nums2[i]]++;
    }
    int* arr = malloc(1001*sizeof(int));
    int number = 0;
    for(int i=0 ; i<=1000 ; i++){
        if(freq1[i]<=freq2[i] && freq1[i]!=0 && freq2[i]!=0){
            for(int j=0 ; j<freq1[i] ; j++){
                arr[number] = i;
                number++;
            }
        }
        else if(freq1[i]>freq2[i] && freq1[i]!=0 && freq2[i]!=0){
            for(int j=0 ; j<freq2[i] ; j++){
                arr[number] = i;
                number++;
                }
            }
        else
            continue;
        }
    arr = realloc(arr,number*sizeof(int));
    *returnSize = number;
    return arr;
}
