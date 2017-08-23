class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        if (a.size() == 0)  return 0;
        int n = a.size(), m = a[0].size(), ans = INT_MIN;
        for (int l = 0; l < m; ++l) {
            int sum[n];
            memset(sum, 0, sizeof(sum));
            for (int r = l; r < m; ++r) {
                set<int> S;
                S.insert(0);
                for (int i = 0; i < n; ++i) sum[i] += a[i][r];
                int tot = 0;
                for (int i = 0; i < n; ++i) {
                    tot += sum[i];
                    auto it = S.lower_bound(tot - k);
                    if (it != S.end())  ans = max(ans, tot - *it);
                    S.insert(tot);
                }
            }
        }
        return ans;
    }
};