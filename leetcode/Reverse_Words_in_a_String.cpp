class Solution {
public:
string reverseWords(string s) {
        // Remove all initial and ending spaces
        int n = s.size();
        string temp;
        for (int i = 0; i < n; ) {
            while (i < n && s[i] == ' ') i++;  // skip spaces
            if (i >= n) break;
            if (!temp.empty()) temp += ' ';     // add single space between words
            string word;
            while (i < n && s[i] != ' ') word += s[i++];
            temp += word;
        }

        // Reverse entire string
        reverse(temp.begin(), temp.end());
        
        // Reverse each word
        int start = 0;
        for (int i = 0; i <= temp.size(); i++) {
            if (i == temp.size() || temp[i] == ' ') {
                reverse(temp.begin() + start, temp.begin() + i);
                start = i + 1;
            }
        }
        return temp;
    }
};