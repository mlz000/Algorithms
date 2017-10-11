int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, f[51 * 51], sz[51 * 51];
class Solution {
public:
    int find(int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    }
    int maxAreaOfIsland(vector<vector<int>>& a) {
        n = a.size();
        if (!n) return 0;
        m = a[0].size();
        int ans = 0;
        memset(sz, 0, sizeof(sz));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                f[i * m + j] = i * m + j;
                if (a[i][j] == 1)   sz[i * m + j] = 1;
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 1) {
                    for (int k = 0; k < 4; ++k) {
                        int tx = i + dx[k], ty = j + dy[k];
                        if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] == 1) {
                            int fa = find(i * m + j), fb = find(tx * m + ty);
                            if (fa != fb)   f[fb] = fa, sz[fa] += sz[fb], ans = max(ans, sz[fa]);
                        }
                    }
                }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int fa = find(i * m + j);
                ans = max(ans, sz[fa]);
            }
        return ans;
    }
};