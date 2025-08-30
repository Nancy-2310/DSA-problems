class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        
        int totalSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        if (windowSize == 0) return totalSum;
        
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }
        
        int minSum = windowSum;
        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = min(minSum, windowSum);
        }
        
        return totalSum - minSum;
    }
};