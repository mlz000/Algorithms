class Solution {
public:
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    bool vis[101][101];
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int lastd = -1, cnt = 1;
        vector<vector<int> > ans;
        int lastr = r0, lastc = c0;
        ans.push_back({r0, c0});
        vis[r0][c0] = 1;
        while (cnt != R * C) {
            int nowd = (lastd + 1) % 4;
            int nowr = lastr + dr[nowd];
            int nowc = lastc + dc[nowd];
            if (nowr >= 0 && nowr < R && nowc >= 0 && nowc < C) {
                if (!vis[nowr][nowc]) {
                    vis[nowr][nowc] = 1;
                    ++cnt;
                    lastr = nowr;
                    lastc = nowc;
                    lastd = nowd;
                    ans.push_back({nowr, nowc});
                }
                else {
                    lastr += dr[lastd];
                    lastc += dc[lastd];
                    if (lastr >= 0 && lastr < R && lastc >= 0 && lastc < C) {
                        if (!vis[lastr][lastc]) {
                            vis[lastr][lastc] = 1;
                            ++cnt;
                            ans.push_back({lastr, lastc});
                        }
                    }
                }
            }
            else {
                lastr = nowr;
                lastc = nowc;
                lastd = nowd;
            }
            cout << lastr << " " << lastc << endl;
        }
        return ans;
    }
};
