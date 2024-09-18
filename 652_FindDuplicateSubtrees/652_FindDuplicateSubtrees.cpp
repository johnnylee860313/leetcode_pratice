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
/*preorder traversal then turn into string and put into hash map
O(n^2),O(n)*/
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> dup_res;
        unordered_map<string,int>treestring;
        preorderdfs(root,treestring,dup_res);
        return dup_res;   
    }
    string preorderdfs(TreeNode *root, unordered_map<string,int>& treestring, vector<TreeNode*>& dup_res){
        if (!root) return "#";
        string str = to_string(root->val) + "," + preorderdfs(root->left, treestring, dup_res) + "," + preorderdfs(root->right, treestring, dup_res);
        if (treestring[str] == 1)dup_res.push_back(root);
        treestring[str]++;
        return str;
    }
};