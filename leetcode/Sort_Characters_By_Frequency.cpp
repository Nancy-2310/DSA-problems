class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> vec(123);
        int n = s.size();

        for(char ch : s){
           int freq = vec[ch].second;
           vec[ch] = {ch, freq + 1};
        }

        auto comp = [&](pair<char, int> &p1, pair<char, int> &p2){
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), comp);

        string result = "";

        for(int i = 0; i <= 122; i++){
           result += string(vec[i].second, vec[i].first); 
        }

        return result;
    }
};