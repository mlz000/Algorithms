typedef pair<int, int> pii;
class Solution {
public:
    int find(int x) {
        return f[x] == x ? x : find(f[x]);
    }
    void merge(int t1, int x, int y) {
        int t2 = x * m + y;
        int ft1 = find(t1), ft2 = find(t2);
        if (ft1 != ft2) {
            if (sz[ft1] < sz[ft2])   f[ft1] = ft2, sz[ft2] += sz[ft1];
            else f[ft2] = ft1, sz[ft1] += sz[ft2];
        }
    }
    bool check(int x, int y, vector<vector<char>>& a) {
        return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'O');
    }
    void solve(vector<vector<char>>& a) {
        n = a.size();
        if (n == 0) return;
        m = a[0].size();
        f.resize(n * m + 1), sz.resize(n * m + 1);
        for (int i = 0; i <= n * m; ++i)    f[i] = i, sz[i] = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'O') {
                    int now = i * m + j;
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1)   merge(now, n - 1, m);
                    if (check(i, j + 1, a)) merge(now, i, j + 1);
                    if (check(i, j - 1, a)) merge(now, i, j - 1);
                    if (check(i + 1, j, a)) merge(now, i + 1, j);
                    if (check(i - 1, j, a)) merge(now, i - 1, j);
                }
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) 
                if (a[i][j] == 'O' && find(i * m + j) != find(n * m)) a[i][j] = 'X';
    }
private:
    int n, m;
    vector<int> f, sz;
};