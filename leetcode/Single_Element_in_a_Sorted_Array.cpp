class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        // Ensure mid is even for easier comparison
        if (mid % 2 == 1) mid--;
        // If pair is intact, single element is in right half
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        }
        // If pair is broken, single element is in left half
        else {
            right = mid;
        }
    }
    return nums[left];
    }
};