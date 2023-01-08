/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* last = NULL;

bool validate(struct TreeNode* root) {
    printf("last %d\n", last);
    if (!root) return true;
    if (!validate(root->left)) return false;
    if ((last != NULL) && (root->val <= last->val)) return false;
    last = root;
    return validate(root->right);
}

bool isValidBST(struct TreeNode* root) {
    last = NULL;
    return validate(root);
}

