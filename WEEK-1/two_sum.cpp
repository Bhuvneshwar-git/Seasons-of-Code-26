class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hash[nums[i]] = i;
        }

        vector<int> ans(2, 0);

        for (int i = 0; i < n; i++) {
            int remains = target - nums[i];
            if (hash.count(remains) && hash[remains] != i) {
                ans[0] = i;
                ans[1] = hash[remains];
                break;
            }
        }
        return ans;
        
    }
};