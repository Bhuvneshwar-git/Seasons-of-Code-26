class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> arr;
        int i = 0;
        while (i < n) {
            if (s[i] != ' ') {
                string temp;
                while(s[i] != ' ' && i < n) {
                    temp += s[i];
                    i++;
                }
                arr.push_back(temp);
            }
            else i++;
        }
        string ans;
        for (int i = arr.size() - 1; i >= 0; i--) {
            ans += arr[i];
            if (i != 0) ans += ' ';
        }
        return ans;
        
    }
};