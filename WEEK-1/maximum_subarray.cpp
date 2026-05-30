class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int curr_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_max = max(curr_max + nums[i], nums[i]);
            ans = max(ans, curr_max);
        }

        return ans;

        
    }
};