class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int ans = 0;
        for (int i = 0; i < (1 << matrix[0].size()); ++i) {
            if (__builtin_popcount(i) != numSelect)  continue;
            int now = 0;
            for (int row = 0; row < matrix.size(); ++row) {
                bool ok = true;
                for (int col = 0; col < matrix[0].size(); ++col) {
                    if (matrix[row][col] == 1 && !(i >> col & 1)) {
                        ok = false;
                    }
                }
                if (ok) ++now;
            }
            ans = max(ans, now);
        }
        return ans;
    }
};
