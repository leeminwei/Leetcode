/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(int* sum, struct TreeNode* root){
    if (root->right != NULL) {
        inorder(sum, root->right);
    }
    root->val = root->val + (*sum);
    (*sum) = root->val;
    if (root->left != NULL) {
        inorder(sum, root->left);
    }
    return;
}
struct TreeNode* bstToGst(struct TreeNode* root) {
    int sum = 0;
    struct TreeNode* cur = root; 
    inorder(&sum, cur);
    return root;
}