class Solution {
public:
    bool search(vector<int>& nums, int target) {     
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return true;
        if(nums[left] == nums[mid] && nums[mid] == nums[right]){
            left++;
            right--;
            continue;
        }
        // Check if left half is sorted
        if (nums[left] <= nums[mid]) {
            // Target is in left sorted half
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        // Right half is sorted
        else {
            // Target is in right sorted half
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return false;
}
};