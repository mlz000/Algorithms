class Solution {
public:
    int dp[505][505];
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 501;
        stations.push_back({target, 0});
        stations.insert(stations.begin(), {0, 0});
        int n = stations.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0] = startFuel;
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j <= i; ++j) {
                if (~dp[i][j]) {
                    int dis = stations[i + 1][0] - stations[i][0];
                    if (dp[i][j] >= dis) {
                        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - dis);
                        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] - dis + stations[i + 1][1]);
                    }
                }
            }
        bool ok = 0;
        for (int i = 0; i < n; ++i)
            if (~dp[n - 1][i]) {
                ok = 1;
                ans = min(ans, i);
            }
        if (!ok)    ans = -1;
        return ans;
    }
};
