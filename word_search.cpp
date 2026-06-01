class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        bool ans = false;

        for (int i = 0; i < m && (!ans); i++) {
            for (int j = 0; j < n && (!ans); j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    ans =( ans || ex(board, word, i, j, 1, visited));
                    visited[i][j] = 0;
                }
            }
        }

        return ans;
    }

    bool ex(vector<vector<char>>& board, string word, int i, int j, int start, vector<vector<int>>& visited) {
        if (start == word.length()) return true;

        bool ans = false;
        int m = board.size();
        int n = board[0].size(); 

        int dx = 1;
        int dy = 0;

        int count = 0;

        while (!ans && count < 4) {
            if (((0 <= i+dx) && (i+dx < m)) && ((0 <= j+dy) && (j+dy < n)) && !visited[i+dx][j+dy] && board[i+dx][j+dy] == word[start]) {
            visited[i+dx][j+dy] = 1;
            ans = ans || ex(board, word, i+dx, j+dy, start+1, visited);
            visited[i+dx][j+dy] = 0;
            }
            dx = dx - dy;
            dy = dx + dy;
            dx = dx - dy;
            count++;
        }

        return ans;

    }
};