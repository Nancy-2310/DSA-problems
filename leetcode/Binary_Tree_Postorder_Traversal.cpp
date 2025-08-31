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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
    if (!root) return result;

    stack<pair<TreeNode*, bool>> st;
    st.push({root, false});

    while (!st.empty()) {
        auto [node, visited] = st.top();
        st.pop();

        if (!node) continue;

        if (visited) {
            result.push_back(node->val); // print when visited=true
        } else {
            st.push({node, true}); // process later
            if (node->right) st.push({node->right, false});
            if (node->left) st.push({node->left, false});
        }
    }

    return result;
    }
};