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

/*
Inorder : LDR
Poatorder : LRD
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeDFS(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);    
    }
    TreeNode* buildTreeDFS(vector<int>& inorder,int istart,int iend, vector<int>& postorder, int pstart, int pend) {
        if (istart > iend || pstart > pend)return NULL;

        // TreeNode* curr = (TreeNode*)malloc(sizeof(TreeNode));
        TreeNode *curr = new TreeNode(postorder[pend]);//root

        /*find the root in inorder seq*/
        int i = 0;
        for(i = istart;i < inorder.size();++i){
            if (inorder[i] == curr->val)break;
        }
        
        /*build the left and right subtree*/
        curr->left = buildTreeDFS(inorder, istart, i-1, postorder, pstart, pstart+i-istart-1);
        curr->right = buildTreeDFS(inorder, i+1, iend, postorder, pstart+i-istart, pend-1);
        return curr;
    }
};