class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex; // stores last index of each char
    int left = 0, right = 0, maxLen = 0;
    int n = s.size();

    while (right < n) {
        char c = s[right];

        // If duplicate and inside the current window
        if (charIndex.count(c) && charIndex[c] >= left) {
            left = charIndex[c] + 1; // shrink window from left
        }

        charIndex[c] = right; // update last seen index
        maxLen = max(maxLen, right - left + 1);

        right++; // move window forward
    }

    return maxLen;
    }
};