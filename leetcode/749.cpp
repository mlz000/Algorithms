const int N = 55;
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int v[N][N], wall[N * N], cnt2[N * N];
    int n, m;
    vector<vector<int> > g;
    bool check(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(int x, int y, int c) {
        v[x][y] = c;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (check(tx, ty) && !v[tx][ty] && g[tx][ty] == 1)
                dfs(tx, ty, c);
        }
    }
    int containVirus(vector<vector<int>>& grid) {
        g = grid;
        n = g.size(), m = g[0].size();
        int ans = 0;
        while (1) {
            int cnt = 0;
            memset(v, 0, sizeof(v));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (g[i][j] == 1 && !v[i][j])
                        dfs(i, j, ++cnt);
            int mx = -1;
            memset(wall, 0, sizeof(wall));
            memset(cnt2, 0, sizeof(cnt2));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    if (g[i][j] == 0) {
                        set<int> mem;
                        for (int k = 0; k < 4; ++k) {
                            int tx = i + dx[k], ty = j + dy[k];
                            if (!check(tx, ty) || g[tx][ty] != 1) continue;
                            ++wall[v[tx][ty]];
                            if (mem.find(v[tx][ty]) != mem.end()) continue;
                            mem.insert(v[tx][ty]);
                            ++cnt2[v[tx][ty]];
                            if (mx == -1 || cnt2[v[tx][ty]] > cnt2[mx]) mx = v[tx][ty];
                        }
                    }
                }
            if (mx == -1)   return ans;
            ans += wall[mx];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (v[i][j] == mx)  
                        g[i][j] = -1;
            vector<vector<int> > tg = g;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (tg[i][j] == 0) {
                        for (int k = 0; k < 4; ++k) {
                            int tx = i + dx[k], ty = j + dy[k];
                            if (check(tx, ty) && g[tx][ty] == 1)    tg[i][j] = 1;
                        }
                    }
            g = tg;
        } 
    }
};