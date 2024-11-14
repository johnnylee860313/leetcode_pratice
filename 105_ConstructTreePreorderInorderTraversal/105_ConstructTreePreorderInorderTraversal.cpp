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
//O(N),O(N)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return buildDFS(preorder, inorder, index, 0, inorder.size()-1);
    }
    TreeNode* buildDFS(vector<int>& preorder, vector<int>& inorder, int& index, int start, int end){
        if(start > end)return NULL;
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int split;
        for(split = 0; split < inorder.size();split++){
            if (inorder[split] == preorder[index])break;
        }
        index++;
        
        root->left = buildDFS(preorder, inorder, index, start, split-1);
        root->right = buildDFS(preorder, inorder, index, split+1, end);
        return root;
    }
};