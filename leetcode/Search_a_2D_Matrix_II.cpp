class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Start from bottom-left corner
    int row = rows - 1;
    int col = 0;
    
    while (row >= 0 && col < cols) {
        int current = matrix[row][col];
        
        if (current == target) {
            return true;
        } else if (current > target) {
            row--; // Move up
        } else {
            col++; // Move right
        }
    }
    
    return false;
    }
};