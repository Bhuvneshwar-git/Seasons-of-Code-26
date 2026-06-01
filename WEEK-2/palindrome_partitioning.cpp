class Solution {
private:
    vector<vector<string>> out;
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        part(s, 0, curr);
        return out;
        
    }

    bool isPalindrome(string s) {
        bool ans = true;

        int n = s.size();

        for (int i = 0; i < n/2; i++) {
            if (s[i] != s[n-i-1]) {
                ans = false;
                break;
            }
        }

        return ans;
    }

    void part(string s, int done, vector<string>& curr) {
        if (done == s.length()) {
            out.push_back(curr);
            return;
        }

        string iter = "";

        for (int i = done; i < s.length(); i++) {
            iter += s[i];
            if (isPalindrome(iter)) {
                curr.push_back(iter);
                part(s, i+1, curr);
                curr.pop_back();
            }
        }
    }
};