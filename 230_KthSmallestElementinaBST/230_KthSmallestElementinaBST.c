/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// traverse BST with inorder traversal will have a sorted sequence
//maintain an counter to record the index now when travaling with inorder seq
//the counter should be global,notice the parameter in function findKthsmallest() when it's called by kthSmallest()
struct TreeNode* findkthsamllest(struct TreeNode* root,int k,int* count){
    if(!root) return NULL;
    
    //inorder traversal
    struct TreeNode* next = findkthsamllest(root->left,k,count);
    
    if(next != NULL) return next;//means find the value
    
    if(++(*count) == k) return root;
    printf("%d b\n",*count);

    return findkthsamllest(root->right,k,count);
}

int kthSmallest(struct TreeNode* root, int k){
    struct TreeNode *result = NULL;
    int count = 0;
    result = findkthsamllest(root,k,&count);

    if(result){
        return result->val;
    }else{
        return NULL;
    }
}