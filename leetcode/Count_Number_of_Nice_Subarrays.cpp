class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int left = 0, oddCount = 0, result = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) oddCount++;
            
            while (oddCount > k) {
                if (nums[left] % 2 == 1) oddCount--;
                left++;
            }
            
            result += right - left + 1;
        }
        return result;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int a = atMost(nums, k);
        int b = atMost(nums, k - 1);

        return a - b;
    }
};