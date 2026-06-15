class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> monostack;
        for (int i = 0; i < n; i++) {
            while (!monostack.empty() && temperatures[monostack.top()] < temperatures[i]) {
                ans[monostack.top()] = i;
                monostack.pop();
            }
            monostack.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (ans[i]) ans[i] -= i;
        }
        return ans;

        
    }
};