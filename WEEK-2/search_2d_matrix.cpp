class Solution {
public:
    int getElement(vector<vector<int>>& matrix, int& mid) {
        int j = 0;
        int i = mid;
        while (i/(matrix[0].size())) {
            i -= (matrix[0].size());
            j++;
        }
        return matrix[j][i];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        int hi = matrix.size() * matrix[0].size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int i = getElement(matrix, mid);
            if (i < target) lo = mid + 1;
            else if (i > target) hi = mid - 1;
            else return true;
        }

        return (getElement(matrix, lo) == target);
        
    }
};