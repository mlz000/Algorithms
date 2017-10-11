/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.
*/
vector<pair<int, int> > g[51 * 51];
#define F first
#define S second
#define mp make_pair
int vis[51][51];
bool cnt[51 * 51];
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& a, int now) {
        vis[x][y] = now;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] == 1 && vis[tx][ty] == -1) {
                dfs(tx, ty, a, now);
            }
        }
    }
    int numDistinctIslands(vector<vector<int>>& a) {
        n = a.size();
        if (!n) return 0;
        m = a[0].size();
        int now = 0;
        memset(vis, -1, sizeof(vis));
        for (int i = 0; i < 50 * 50; ++i)   g[i].clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 1 && vis[i][j] == -1) {
                    dfs(i, j, a, now);
                    now++;
                }
        for (int i = 0; i < n; ++i) {
            int t = 0;
            int j = 0;
            while (j < m) {
                if (vis[i][j] != -1) {
                    if (j == 0 || (j > 0 && vis[i][j] != vis[i][j - 1])) {
                        g[vis[i][j]].push_back(mp(0, j));
                    }
                    else ++g[vis[i][j]][g[vis[i][j]].size() - 1].F;
                }
               ++j;
            }
        }
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i = 0; i < now; ++i) {
            if (cnt[i])    continue;
            ++ans;
            for (int j = i + 1; j < now; ++j) {
                if (g[i].size() == g[j].size()) {
                    bool ok = 1;
                    for (int k = 0; k < g[i].size(); ++k) {  
                        if (g[i][k].F != g[j][k].F) {
                            ok = 0;
                            break;
                        }
                        else {
                            if (k != 0 && g[i][k].S - g[i][k - 1].S != g[j][k].S - g[j][k - 1].S) {
                                ok = 0;
                                break;
                            }
                        }
                    }
                    if (ok) cnt[j] = 1;
                }
            }
        }
        return ans;
    }
};