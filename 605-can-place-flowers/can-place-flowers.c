bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int index = 0;
    if(n==0) return true;
    if(flowerbedSize==1&&n==1&&flowerbed[0]==0) return true;
    for(int i=0 ; i<flowerbedSize-1 ; i++){
        if(i==0 || i==flowerbedSize-2){
            if(flowerbed[i]==0 && flowerbed[i+1]==0){
                n--;
                flowerbed[i]=1;
            }
        }
        else{
            if(flowerbed[i]==0 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
                n--;
                flowerbed[i]=1;
            }
        }
        if(n==0)
            return true;
    }
    return false;
}