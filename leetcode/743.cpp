class Solution {
public:
    int d[101][101];
    int networkDelayTime(vector<vector<int>>& a, int N, int K) {
        memset(d, 0x3f3f3f3f, sizeof(d));
        for (auto x : a) {
            d[x[0]][x[1]] = min(d[x[0]][x[1]], x[2]);
        }
        for (int i = 1; i <= N; ++i)    d[i][i] = 0;
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int ans = 0;
        for (int i = 1; i <= N; ++i)    ans = max(ans, d[K][i]);
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};