class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int lo = 0;
        int ans = 0;
        for (int hi = 0; hi < s.length(); hi++) {
            if (!(hash[s[hi]] <= lo)) {
                lo = hash[s[hi]];
                hash[s[hi]] = hi + 1;
            }
            else hash[s[hi]] = hi + 1;

            ans = max(ans, hi - lo + 1);
        }
        return ans;

        
    }
};