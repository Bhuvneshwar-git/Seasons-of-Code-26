class Solution {
private:
    vector<string> out;
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        para(n, 0, 0, curr);
        return out;
    }

    void para(int n, int open, int close, string& curr) {
        if (close > open) return;
        if (close == n && open == n) {
            out.push_back(curr);
            return;
        }

        if (open < n) {
            curr += "(";
            para(n, open+1, close, curr);
            curr.pop_back();
        }
        if (close < n) {
            curr += ")";
            para(n, open, close+1, curr);
            curr.pop_back();
        }
    }
};