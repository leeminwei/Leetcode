int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);
    int left=0;
    int right=0;
    int count = 0;
    if(sSize==0) return 0;
    while(right < sSize && left < gSize){
        if(s[right]>=g[left]){
            count++;
            right++;
            left++;
        }
        else
            right++;
    }
    return count;
}