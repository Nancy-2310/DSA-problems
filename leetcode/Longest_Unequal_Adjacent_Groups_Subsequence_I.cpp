class Solution {
public:
   
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        int num = groups[0];
        ans.push_back(words[0]);
        for(int i  = 1; i < n; i++){
            if(groups[i] != num){
                num = groups[i];
                ans.push_back(words[i]);
            }
            
        }
        return ans;
    }
};