class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seqs;
        for (int i : nums) {
            seqs[i] = true;
        }
        for (int i : nums) {
            if (seqs.count(i-1)) seqs[i] = false;
        }

        int ans = 0;
        for (int i : nums) {
            if (seqs[i]) {
                int j = 1;
                while (seqs.count(i+j)) j++;
                ans = max(ans, j);
            }
        }

        return ans;

        
    }
};