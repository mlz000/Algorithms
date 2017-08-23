class Solution {
public:
    int minCut(string t) {
        string s = "?#";
		for (auto ss : t)	s += ss, s += '#';
		int mx = 0, id = 0;
		int n = s.size();
		vector<int> p(n, 0), dp(n, 100000);
		dp[0] = dp[1] = -1;
		for (int i = 2; i < n; ++i) {
			for (; s[i + p[i]] == s[i - p[i]]; ++p[i])	dp[i + p[i]] = min(dp[i + p[i]], dp[i - p[i] - 1] + 1);
		}
		return min(dp[n - 1], dp[n - 2]);
    }
}; 