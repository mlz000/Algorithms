class Solution {
public:
    int f[105][52][52];
    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i <= 102; ++i)
            for (int j = 0; j <= 50; ++j)
                for (int k = 0; k <= 50; ++k)
                    f[i][j][k] = -1e7;
        f[1][1][1] = a[0][0];
        for (int k = 2; k <= n + m - 1; ++k)
            for (int i = 1; i <= k && i <= n; ++i)
                for (int j = 1; j <= k && j <= n; ++j) {
                    int x;
                    if (a[i - 1][k - i] == -1 || a[j - 1][k - j]== -1) continue;
                    if (i == j) x = a[i - 1][k - i];
                    else x = a[i - 1][k - i] + a[j - 1][k - j];
                    f[k][i][j] = max(max(f[k - 1][i][j], f[k - 1][i - 1][j - 1]), max(f[k - 1][i][j - 1], f[k - 1][i - 1][j])) + x;
                }
        if (f[n + m - 1][n][m] > 0) return f[n + m - 1][n][m];
        else return 0;
    }
};