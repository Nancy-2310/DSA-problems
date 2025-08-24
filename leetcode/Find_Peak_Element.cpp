class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
       
        if (nums[mid] > nums[mid + 1]) {
            right = mid; // mid could be the peak
        }
        // If mid is smaller than next element, peak is in right half
        else {
            left = mid + 1; 
        }
    }
    return left; // left == right at this point
    }
};