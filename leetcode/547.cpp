const int N = 205;
class Solution {
public:
    int f[N], ans[N];
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    int findCircleNum(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 1; i <= n; ++i) f[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (a[i][j] == 1) {
                    int fi = find(i + 1), fj = find(j + 1);
                    if (fi != fj)   f[fi] = fj;
                }
        for (int i = 1; i <= n; ++i)
            ans[find(i)] = 1;
        int res = 0;
        for (int i = 1; i <= n; ++i) res += ans[i];
        return res;
    }
};