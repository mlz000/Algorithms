class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n, 0));
        int now = 0;
        int u = 0, d = n - 1, l = 0, r = n - 1;
        while (1) {
            for (int i = l; i <= r; ++i)    ans[u][i] = ++now;
            if (++u > d)    break;
            for (int i = u; i <= d; ++i)    ans[i][r] = ++now;
            if (--r < l)    break;
            for (int i = r; i >= l; --i)    ans[d][i] = ++now;
            if (--d < u)    break;
            for (int i = d; i >= u; --i)    ans[i][l] = ++now;
            if (++l > r)    break;
        }
        return ans;
    }
};