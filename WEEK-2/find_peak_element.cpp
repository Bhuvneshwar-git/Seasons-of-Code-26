class Solution {
public:
    int type(vector<int>& nums, int k) {
        if (nums[k] < nums[k+1]) {
            if (nums[k] < nums[k-1]) return 0;
            else return 2;
        }
        else {
            if (nums[k] < nums[k-1]) return 3;
            else return 1;
        }

    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int lo = 1;
        int hi = n-2;
        if (n == 1) return 0;
        else if (nums[1] < nums[0]) return 0;
        else if (nums[n-1] > nums[n-2]) return n-1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int typ = type(nums, mid);
            if (typ == 1) return mid;
            else if (typ == 2) lo = mid + 1;
            else hi = mid - 1;
        }
        return lo;
        
    }
};