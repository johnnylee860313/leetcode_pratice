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
    TreeNode* helper(TreeNode* node, bool was_root, unordered_set<int>& hash, vector<TreeNode*>& res){
        if(!node)return NULL;
        bool is_del = hash.count(node->val); 
        if(!is_del && was_root) res.push_back(node);
        node->left = helper(node->left,is_del,hash,res);
        node->right = helper(node->right,is_del,hash,res);
        return is_del?NULL: node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> hash(to_delete.begin(),to_delete.end());
        vector<TreeNode*> res;
        helper(root, true, hash, res);
        return res;
    }
};