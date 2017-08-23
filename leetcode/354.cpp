typedef pair<int, int> pii;
#define F first
#define S second
class Solution {
public:
    int maxEnvelopes(vector<pii>& a) {
        int ans = 1, n = a.size();
        if (n == 0) return 0;
        int dp[n];
        sort(a.begin(), a.end(), [](pii &a, pii &b) {
            return a.F < b.F || (a.F == b.F && a.S > b.S);
        });
        dp[0] = a[0].S;
        for (int i = 1; i < n; ++i) {
            if (a[i].S > dp[ans - 1]) dp[ans++] = a[i].S;
            else *lower_bound(dp, dp + ans, a[i].S) = a[i].S;
        }
        return ans;
    }
};