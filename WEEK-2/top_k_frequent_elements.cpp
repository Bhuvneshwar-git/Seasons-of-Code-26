class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }        

        vector<vector<int>> freq(nums.size()+1);
        for (auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> ans;
        int counter = 0;
        for (int i = nums.size(); i >= 0; i--) {
            if (!freq[i].empty()) {
                for (int item : freq[i]) {
                    ans.push_back(item);
                    counter++;
                    if (counter == k) return ans;
                }
            }
        }

        return ans;

    }

};