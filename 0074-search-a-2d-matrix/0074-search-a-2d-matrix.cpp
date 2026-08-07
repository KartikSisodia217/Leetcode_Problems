class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m - 1;
        int row = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] == target)
                return true;

            if (matrix[mid][0] < target) {
                row = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (row == -1)
            return false;

        l = 0;
        r = n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return false;
    }
};