class Solution {
public:
    bool isPalindrome(string s) {
        bool ans = true;
        string valid;
        for (char c : s) {
            if (isalnum(c)) {
                valid += tolower(c);
            }
        }
        int n = valid.size();

        for (int i = 0; i < n/2; i++) {
            if (valid[i] != valid[n-i-1]) {
                ans = false;
                break;
            }
        }

        return ans;


        
    }
};