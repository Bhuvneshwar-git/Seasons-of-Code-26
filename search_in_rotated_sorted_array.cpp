class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1; 
        
        int lo = 0, hi = n - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1; 
            else hi = mid;                         
        }

        int root = lo;
        lo = 0;
        hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[(mid + root) % n] < target) lo = mid + 1;
            else hi = mid;
        }

        if (nums[(lo + root) % n] == target) return (lo + root) % n;
        else return -1;
    }
};