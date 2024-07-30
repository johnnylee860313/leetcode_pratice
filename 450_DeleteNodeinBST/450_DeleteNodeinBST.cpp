/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //pick the left most node in the right subtree of the key node as new root
        if(root == NULL)return root;
        if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else{
            TreeNode* new_root = NULL;
            if(root->left == NULL){
                new_root = root->right;
            }else if(root->right == NULL){
                new_root = root->left;
            }else{
                TreeNode* parent = root;
                new_root = root->right;
                while(new_root->left != NULL){
                    parent = new_root;
                    new_root = new_root->left;
                }
                //replace the key node with new_root
                if(parent != root){
                    parent->left = new_root->right;
                    new_root->right = root->right;
                }
                new_root->left = root->left;
            }
            delete root;
            return new_root;
        }
        return root;
    }
    
};