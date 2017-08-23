const int N = 2005;
class Solution {
public:
	bool dp[N][N];
    bool isMatch(string s, string p) {
        int l1 = s.size(), l2 = p.size();
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int j = 1; j <= l2; ++j) {
			if (p[j - 1] == '*')	dp[j][0] = dp[j - 1][0];
			for (int i = 1; i <= l1; ++i) {
				if ((s[i - 1] == p[j - 1]) || p[j - 1] == '?')	dp[j][i] |= dp[j - 1][i - 1];
				else if (p[j - 1] == '*')	dp[j][i] |= dp[j - 1][i] | dp[j][i - 1]; 
			}
		}
		return dp[l2][l1];
    }
};