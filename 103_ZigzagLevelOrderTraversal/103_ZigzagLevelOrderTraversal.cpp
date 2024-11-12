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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> output;
        ztraverse(output, 0,root);
        return output;
    }
    
    void ztraverse(vector<vector<int>>& output, int depth, TreeNode* root){
        if(!root)return;
        while(output.size() <= depth){
            output.push_back({}); //extend the output size 
        }
        
        if (depth % 2 == 0){//add from tail
            output[depth].push_back(root->val);
        } else {
            output[depth].insert(output[depth].begin(), root->val);// add from head
        }
        
        ztraverse(output, depth+1, root->left);
        ztraverse(output, depth+1, root->right);
        return;
    }
};