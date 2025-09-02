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
   bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;          // दोनों null -> symmetric
        if (!t1 || !t2) return false;         // एक null और दूसरा non-null -> not symmetric
        return (t1->val == t2->val) &&      // values equal
               isMirror(t1->left, t2->right) &&   // left-right check
               isMirror(t1->right, t2->left);     // right-left check
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};