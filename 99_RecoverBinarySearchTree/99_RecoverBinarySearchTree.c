/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* fault1 = NULL;
struct TreeNode* fault2 = NULL;
struct TreeNode* last = NULL;

void validateBST(struct TreeNode* root){
    if(!root)return;
    validateBST(root->left);
    if(last && root->val <= last->val){
        if(!fault1)fault1 = last;
        fault2 = root;
    }
    last = root;
    validateBST(root->right);
}

void recoverTree(struct TreeNode* root){
    int tempt = NULL;
    fault1 = NULL;
    fault2 = NULL;
    last = NULL;
    validateBST(root);
    tempt = fault1->val;
    fault1->val = fault2->val;
    fault2->val = tempt;
}