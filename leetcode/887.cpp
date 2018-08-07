class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            int mx = 0;
            for (int j = 0; j < n; ++j) {
                mx = max(mx, grid[i][j]);
                ans += (grid[i][j] > 0);
            }
            ans += mx;
        }
        for (int j = 0; j < n; ++j) {
            int mx = 0;
            for (int i = 0; i < n; ++i) {
                mx = max(mx, grid[i][j]);
            }
            ans += mx;
        }
        return ans;
    }
};
