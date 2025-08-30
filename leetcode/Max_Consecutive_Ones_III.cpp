class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, maxLen = 0;
    int n = nums.size();

    while (right < n) {
        if (nums[right] == 0) {
            k--; // use one flip
        }

        // If more than k zeros in window, shrink from left
        while (k < 0) {
            if (nums[left] == 0) {
                k++; // give back a flip
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
    }
};