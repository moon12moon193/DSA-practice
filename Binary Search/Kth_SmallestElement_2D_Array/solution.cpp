class Solution {
public:
    int CalcSmallerNums(int mid,vector<vector<int>>& matrix) {
        int count = 0;
        int row2 = matrix.size() - 1;
        int col2 = 0;
        while (row2 >= 0 && col2 < matrix[0].size()) {
            if (matrix[row2][col2] <= mid) {
                count = count + row2 + 1;
                col2++;

            } else {
                row2--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        int high = matrix[row][col];
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ans = CalcSmallerNums(mid,matrix);
            if (ans < k) {
                low = mid + 1;
            } else { // ans>=k
                res = mid;

                high = mid - 1;
            }
        }
        return res;
    }
};
