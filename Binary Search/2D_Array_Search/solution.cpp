class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        int row = matrix.size();
        int col = matrix[0].size();

        // for calculating row for target

        int low = 0;
        int high = row - 1;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] > target) {
                high = mid - 1;

            } else {
                res = mid;
                low = mid + 1;
            }
        }
        // for calculating col: for exact target value present in col
        if (res == -1) {
            return false;
        } else {
            int row2 = res;

            int low2 = 0;
            int high2 = col - 1;
            while (low2 <= high2) {
                int mid2 = low2 + (high2 - low2) / 2;
                if (matrix[row2][mid2] == target) {
                    return true;
                } else if (matrix[row2][mid2] < target) {
                    low2 = mid2 + 1;
                } else {
                    high2 = mid2 - 1;
                }
            }
            return false;
        }
    }
};
