class Solution {
private: 
    vector<int> place;
    vector<bool> col;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<vector<int>> out;

public:
    void solve(int r, int n) {
        if (r == n) {
            out.push_back(place);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (col[i] || diag1[r+i] || diag2[r-i+n-1]) continue;
            col[i] = diag1[r+i] = diag2[r-i+n-1] = true;
            place[r] = i;
            solve(r+1, n);
            col[i] = diag1[r+i] = diag2[r-i+n-1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        place.assign(n, 0);
        col.assign(n, false);
        diag1.assign(2*n - 1, false);
        diag2.assign(2*n - 1, false);

        solve(0, n);

        vector<vector<string>> ans;
        for (vector<int> item : out) {
            vector<string> it;
            for (int i = 0; i < n; i++) {
                string temp(n, '.');
                temp[item[i]] = 'Q';
                it.push_back(temp);
            }
            ans.push_back(it);
        }

        return ans;


    }
};