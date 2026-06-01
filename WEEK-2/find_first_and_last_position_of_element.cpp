class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.empty()) return ans;
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        if (nums[lo] == target) ans[0] = lo;

        lo = 0;
        hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (nums[mid] <= target) lo = mid;
            else hi = mid - 1;
        }
        if (nums[lo] == target) ans[1] = lo;

        return ans;  
    }
};