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
    int maxSum=0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int l = solve(root -> left);
        int r = solve(root -> right);

        int niche_ans_milgya = l + r + root-> val;
        int only_ek_acha = max(l,r)+root->val;
        int root_acha = root -> val;

        maxSum = max({maxSum, niche_ans_milgya,only_ek_acha,  root_acha});
        return max( root_acha,only_ek_acha);
    }
    int maxPathSum(TreeNode* root) {
       maxSum = INT_MIN;
       solve(root);
       return maxSum;

    }
};
