class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        int k=0;
        while(left<=right){
            if(nums[left]==val && nums[right]!=val){
                swap(nums[left],nums[right]);
                left++;
                right--;
                k++;
            }
            else{
                if(nums[left]!=val){
                   left++; 
                   k++;
                } 
                if(nums[right]==val) right--;
            }
        }
        return k;
    }
};