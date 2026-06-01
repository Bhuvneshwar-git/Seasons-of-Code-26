class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        vector<int> curr;
        combSum(candidates, target, curr, 0);
        return ans;
        
    }

    void combSum(vector<int> candidates, int target, vector<int>& curr, int start) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue;
            curr.push_back(candidates[i]);
            combSum(candidates, target - candidates[i], curr, i);
            curr.pop_back();
        }
        
    }


};