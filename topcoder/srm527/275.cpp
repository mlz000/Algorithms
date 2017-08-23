#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int dp[N][N << 1];
class P8XGraphBuilder {
	public:
	int solve(vector <int> scores) {
		int n = scores.size() + 1;
		memset(dp, -1, sizeof(dp));
		int m = 2 * n - 2;
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				for (int k = 1; k + j <= m; ++k)
					if (~dp[i][j])	dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + scores[k - 1]);
		return dp[n][m];
	}
};
