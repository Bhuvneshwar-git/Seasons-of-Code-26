class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        if (s.size() != t.size()) return false;
        for (char c : s) hash[c] += 1;
        for (char c : t) {
            if (hash[c] == 0) return false;
            else hash[c] -= 1;
        }
        return true;
        
    }
};