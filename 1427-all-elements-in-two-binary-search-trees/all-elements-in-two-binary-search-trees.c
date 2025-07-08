/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(int* arr, int* idx, struct TreeNode* root){
    if (root == NULL) return;
    if (root->left != NULL) {
        inorder(arr, idx, root->left);
    }
    arr[(*idx)++] = root->val;
    if (root->right != NULL) {
        inorder(arr, idx, root->right);
    }
}
void print_array(int* arr, int size){
    for (int i=0 ; i<size ; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int* arr1 = (int*)malloc(5000 * sizeof(int));
    int arr1_idx = 0;
    int* arr2 = (int*)malloc(5000 * sizeof(int));
    int arr2_idx = 0;
    inorder(arr1, &arr1_idx, root1);
    inorder(arr2, &arr2_idx, root2);
    //print_array(arr1, arr1_idx);
    //print_array(arr2, arr2_idx);
    int* answer = (int*)malloc(10000 * sizeof(int));
    int answer_idx = 0;
    int a1 = 0;
    int a2 = 0;
    while (a1 != arr1_idx && a2 != arr2_idx) {
        if (arr1[a1] < arr2[a2]) {
            answer[answer_idx] = arr1[a1];
            a1++;
        }
        else if (arr2[a2] < arr1[a1]) {
            answer[answer_idx] = arr2[a2];
            a2++;
        }
        else{
            answer[answer_idx] = arr1[a1];
            a1++;
        }
        answer_idx++;
    }
    if (a1 != arr1_idx) {
        for (int i=a1 ; i<arr1_idx ; i++) {
            answer[answer_idx++] = arr1[i];
        }
    }
    else if (a2 != arr2_idx) {
        for (int i=a2 ; i<arr2_idx ; i++) {
            answer[answer_idx++] = arr2[i];
        }
    }
    *returnSize = answer_idx;
    return answer;
}