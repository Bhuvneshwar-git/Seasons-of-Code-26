class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) nums[i] = nums[i-1] + nums[i];
            int target = nums[i] - k;
            if (target == 0) count++;
            count += hash[target];
            hash[nums[i]] += 1;

        }

        return count;


        
        
    }
};