class Solution {
public:
    int firstOccurrence(vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1;
    int first = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first = mid; // Found, but continue searching left
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return first;
}

int lastOccurrence(vector<int> arr, int target) {
    int left = 0, right = arr.size() - 1;
    int last = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last = mid; // Found, but continue searching right
            left = mid + 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }
    return last;
}
      
    vector<int> searchRange(vector<int>& nums, int target) {
        
      int a = firstOccurrence(nums, target);
      int b = lastOccurrence(nums, target);

      return {a,b};
    }
};