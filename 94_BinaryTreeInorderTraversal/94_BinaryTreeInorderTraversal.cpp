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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root)return;
        if(root->left)inorder(root->left,ans);
        ans.push_back(root->val);
        if(root->right)inorder(root->right,ans);
        return;
    }
};

//Iterative
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> stk;
//         vector<int> path;
//         TreeNode* current = root;

//         while (!stk.empty() || current != NULL) {
//             while (current != NULL) {
//                 stk.push(current);
//                 current = current->left;
//             }
//             TreeNode* node = stk.top();
//             path.push_back(node->val);
//             stk.pop();
//             current = node->right;
//         }
//         return path;
//     }
// };
