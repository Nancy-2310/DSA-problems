class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size()-1;           // O(1)
    int s = 0;                           // O(1)
    int e = matrix[0].size()-1;          // O(1)

    while(s <= row && e >= 0) {          // Loop runs at most m+n times
        if(matrix[s][e] == target) return true;  // O(1)
        else if(matrix[s][e] < target) s++;      // Move down one row
        else e--;                                // Move left one column
    }

    return false;        
    }
};