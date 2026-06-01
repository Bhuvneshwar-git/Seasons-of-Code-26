class Solution {
public:

    bool canDo(vector<int>& piles, int h, int k) {
        int time = 0;
        for (int pile : piles) {
            time += pile/k + (pile%k == 0 ? 0:1);
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canDo(piles, h, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
        
    }
};