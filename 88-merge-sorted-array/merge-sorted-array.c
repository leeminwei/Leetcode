void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int count = 0;
    int t;
    
    for(int i = m ; i<nums1Size ; i++){
        nums1[i] = nums2[count];
        count++;
    }

    for(int i = 0; i<nums1Size ; i++){
        for(int j = i+1 ; j<nums1Size ; j++){
            if(nums1[j]<nums1[i]){
                t = nums1[i];
                nums1[i] = nums1[j];  
                nums1[j] = t;
            }
            else
                continue;
        }
    }
    
}