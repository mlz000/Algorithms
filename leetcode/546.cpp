int dp[100][100][100];
class Solution {
public:
    int dfs(int l, int r, int k, vector<int>& a) {
        if (l > r)  return 0;
        if (dp[l][r][k])   return dp[l][r][k];
        int &t = dp[l][r][k];
        t = dfs(l, r - 1, 0, a) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++i)
            if (a[i] == a[r])   t = max(t, dfs(l, i, k + 1, a) + dfs(i + 1, r - 1, 0, a));   
        return t;
    }
    int removeBoxes(vector<int>& a) {
        memset(dp, 0, sizeof(dp));
        return dfs(0, a.size() - 1, 0, a);
    }
};