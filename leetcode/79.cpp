class Solution {
public:
    bool dfs(vector<vector<char> >& s, string t, int x, int y, int now) {
        if (x < 0 || x >= n || y < 0 || y >= m) return 0;
        if (s[x][y] != t[now])  return 0;
        if (now == t.size() - 1)    return 1;
        char c = s[x][y];
        s[x][y] = '.';
        if (dfs(s, t, x + 1, y, now + 1))   return 1;
        if (dfs(s, t, x - 1, y, now + 1))   return 1;
        if (dfs(s, t, x, y + 1, now + 1))   return 1;
        if (dfs(s, t, x, y - 1, now + 1))   return 1;
        s[x][y] = c;
        return 0;
    }
    bool exist(vector<vector<char>>& s, string t) {
        n = s.size();
        if (!n) return 0;
        m = s[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (dfs(s, t, i, j, 0)) return 1;
        return 0;
    }
private:
    int n, m;
};