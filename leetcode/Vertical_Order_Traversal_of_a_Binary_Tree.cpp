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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // hd -> list of nodes
        map<int, vector<pair<int,int>>> mp; // hd -> {row, val}
        queue<pair<TreeNode*, pair<int,int>>> q; // {node, {hd, row}}
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int hd = it.second.first;
            int row = it.second.second;
            
            mp[hd].push_back({row, node->val});
            
            if (node->left) q.push({node->left, {hd - 1, row + 1}});
            if (node->right) q.push({node->right, {hd + 1, row + 1}});
        }
        
        vector<vector<int>> ans;
        for (auto& p : mp) {
            auto vec = p.second;
            // Sort by row, then by value 
            sort(vec.begin(), vec.end());
            vector<int> col;
            for (auto& x : vec) col.push_back(x.second);
            ans.push_back(col);
        }
        return ans;
    }
};