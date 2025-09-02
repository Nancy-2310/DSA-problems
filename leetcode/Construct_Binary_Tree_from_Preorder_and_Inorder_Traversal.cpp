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
    unordered_map<int,int> mp;  // value -> index of inorder

    TreeNode* buildBT(vector<int>& inorder, vector<int>& preorder, 
                      int inStart, int inEnd, int preStart, int preEnd) {
        if (inStart > inEnd || preStart > preEnd)
            return NULL;

        // root from preorder's start
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootVal = root->val;

        // find root index in inorder using map
        int i = mp[rootVal];

        int leftSize  = i - inStart;
        int rightSize = inEnd - i;

        // build left and right recursively
        root->left  = buildBT(inorder, preorder, 
                              inStart, i-1, preStart+1, preStart+leftSize);
        root->right = buildBT(inorder, preorder, 
                              i+1, inEnd, preStart+leftSize+1, preEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        // fill map for O(1) lookup
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return buildBT(inorder, preorder, 0, n-1, 0, n-1);
    }
};