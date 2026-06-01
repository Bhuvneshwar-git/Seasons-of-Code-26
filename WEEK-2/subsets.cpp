class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size()==0) {
            vector<vector<int>> ans;
            ans.push_back(nums);
            return ans;
        }
        else {
            int x = nums[nums.size()-1];
            nums.pop_back();
            vector<vector<int>> ans = subsets(nums);
            int i = ans.size()-1;
            for (int j = 0;j<=i;j++) {
                vector<int> dup = ans[j];
                dup.push_back(x);
                ans.push_back(dup);
            }
            return ans;
        }
        
    }
};