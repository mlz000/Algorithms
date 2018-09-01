class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j])    continue;
                ans += 2;
                for (int k = 0; k < 4; ++k) {
                    int di = i + dx[k];
                    int dj = j + dy[k];
                    if (di >= 0 && di < n && dj >= 0 && dj < n) {
                        ans += max(grid[i][j] - grid[di][dj], 0);
                    }
                    else ans += grid[i][j];
                }
            }
        return ans;
    }
};
