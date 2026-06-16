class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> montu;
        heights.push_back(0);
        int best = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!montu.empty() && heights[montu.top()] > heights[i]) {
                int top = montu.top();
                montu.pop();
                int width = montu.empty() ? i : i - montu.top() - 1;
                best = max(best, heights[top]*width);
            }
            montu.push(i);
        }
        return best;    
    }
};