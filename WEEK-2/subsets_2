class Solution {
private:
    vector<vector<int>> out;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (int i : nums) freq[i] += 1;
        vector<int> curr;
        sub(nums, freq, 0, curr);
        return out;
        
    }

    void sub(vector<int>& nums, unordered_map<int, int>& freq, int done, vector<int>& curr) {
        if (done == nums.size()) {
            out.push_back(curr);
            return;
        }

        curr.insert(curr.end(), nums.begin()+done, nums.begin()+done+freq[nums[done]]);
        int j = freq[nums[done]];
        while (j != 0) {
            sub(nums, freq, done+freq[nums[done]], curr);
            curr.pop_back();
            j--;
        }
        sub(nums, freq, done+freq[nums[done]], curr);
    }
};