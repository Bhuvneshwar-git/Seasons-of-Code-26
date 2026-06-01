class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int part = nums[r];
        int i = l;
        for (int j = l; j < r; j++) {
            if (nums[j] <= part) swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }
    void sortColors(vector<int>& nums, int l = 0, int r = -1) {
        if (nums.empty()) return;
        if (r == -1) r = nums.size() - 1;
        if (l >= r) return;
        int part = partition(nums, l, r);
        sortColors(nums, l, part-1);
        sortColors(nums, part + 1, r);   
    }
};