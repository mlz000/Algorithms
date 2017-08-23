const int inf = 2e9;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
	vector<vector<int> > dp(n + 1, vector<int>(m + 1, inf));
	dp[n][m - 1] = dp[n - 1][m] = 1;
    	for (int i = n - 1; i >= 0; --i)
	    for (int j = m - 1; j >= 0; --j) {
		int t = min(dp[i + 1][j], dp[i][j + 1]) - a[i][j];
		dp[i][j] = t <= 0 ? 1 : t;
	    }
	return dp[0][0];
    }
};
