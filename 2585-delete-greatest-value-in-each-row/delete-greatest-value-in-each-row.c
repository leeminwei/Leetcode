void removeMaxInRow(int* row, int* colSize) {
    int maxIdx = 0;

    // 找到最大值的索引
    for (int i = 1; i < *colSize; i++) {
        if (row[i] > row[maxIdx]) {
            maxIdx = i;
        }
    }

    // 刪除最大值（將後面的元素往前移動）
    for (int i = maxIdx; i < (*colSize) - 1; i++) {
        row[i] = row[i + 1];
    }

    // 更新列數
    (*colSize)--;
}

int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
    
    int time = *gridColSize;
    printf("time = %d\n",time);
    int max = 0;
    int answer = 0;
    int copy = 0;
    while(time > 0){
        max = 0;
        for(int i=0 ; i<gridSize ; i++){
            copy = max;
            max = 0;
            for(int j=0 ; j<gridColSize[i] ; j++){
                if(grid[i][j]>max){
                    if(i==0){
                        max = grid[i][j];
                        copy = max;
                    }
                    max = grid[i][j];
                }
            }
            removeMaxInRow(grid[i], &gridColSize[i]);
            if(copy > max)
                max = copy;
        }
        answer = answer + max;
        time--;
    }
    return answer;
}
/*
int answer = 0;
    int time = *gridColSize;
    while (time > 0) { // 當還有剩餘列時繼續
        int maxDeleted = 0;

        // 逐行刪除最大值
        for (int i = 0; i < gridSize; i++) {
            if (gridColSize[i] > 0) { // 確保這一行還有元素
                int prevMax = maxDeleted;
                int currMax = grid[i][0];

                // 找出這一行的最大值
                for (int j = 1; j < gridColSize[i]; j++) {
                    if (grid[i][j] > currMax) {
                        currMax = grid[i][j];
                    }
                }

                // 刪除這一行的最大值
                removeMaxInRow(grid[i], &gridColSize[i]);

                // 更新刪除的最大值
                if (currMax > prevMax) {
                    maxDeleted = currMax;
                }
            }
        }

        answer += maxDeleted; // 加入這一輪刪除的最大值
        time--; // 每輪刪除後列數減少
    }

    return answer;
}*/