#define pb push_back
#define mp make_pair
#define F first
#define S second
class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        if (a.size() == 0)  return 0;
        vector<pair<int, int> > p;
        vector<vector<int> > dp(a.size() + 1, vector<int> (2, 0));
        sort(a.begin(), a.end());
        int j;
        for (int i = 0; i < a.size(); i = j + 1) {
            int sum = 0;
            j = i;
            while (j + 1 < a.size() && a[j + 1] == a[i])    ++j;
            p.push_back(mp(a[i], a[i] * (j - i + 1)));
        }
        dp[0][1] = p[0].S; 
        for (int i = 1; i < p.size(); ++i) {
            if (p[i].F == p[i - 1].F + 1) {
                dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
                dp[i][1] = dp[i - 1][0] + p[i].S;
            }
            else dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]), dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + p[i].S;
        }
        return max(dp[p.size() - 1][0], dp[p.size() - 1][1]);
    }
};