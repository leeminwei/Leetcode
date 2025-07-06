/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(int* arr, int* idx, struct TreeNode* root){
    if (root->left != NULL) {
        inorder(arr, idx, root->left);
    }

    arr[(*idx)++] = root->val;
    printf("arr[%d] = %d\n", (*idx)-1, arr[(*idx)-1]);

    if (root->right != NULL) {
        inorder(arr, idx, root->right);
    }
}

int kthSmallest(struct TreeNode* root, int k) {
    int arr[10000];
    int idx = 0;
    inorder(arr, &idx, root);
    return arr[k-1];
}