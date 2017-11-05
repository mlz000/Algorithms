#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int> ans;
        int n = a.size();
        if (n == 0) return ans;
        int m = a[0].size();
        int u = 0, d = n - 1, l = 0, r = m - 1;
        while (1) {
            for (int i = l; i <= r; ++i)   ans.pb(a[u][i]);
            if (++u > d)    break;
            for (int i = u; i <= d; ++i)    ans.pb(a[i][r]);
            if (--r < l)    break;
            for (int i = r; i >= l; --i)    ans.pb(a[d][i]);
            if (--d < u)    break;
            for (int i = d; i >= u; --i)    ans.pb(a[i][l]);
            if (++l > r)    break;
        }
        return ans;
    }
};