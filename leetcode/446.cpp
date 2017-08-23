typedef long long LL;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
       vector<unordered_map<int, int> >dp(a.size());
       int ans = 0, n = a.size();
       for (int i = 0; i < n; ++i)
           for (int j = 0; j < i; ++j) {
               if ((LL)a[i] - a[j] > INT_MAX || (LL)a[i] - a[j] < INT_MIN)  continue;
               int dif = a[i] - a[j];
               ++dp[i][dif];
               if (dp[j].count(dif)) {
                   dp[i][dif] += dp[j][dif];
                   ans += dp[j][dif];
               }
           }
        return ans;
    }
};