class Solution {
public:
    int g[27][27], d[27], v[27];
    queue<int> q;
    string alienOrder(vector<string>& s) {
        int n = s.size(), m = 0;
        memset(g, 0, sizeof(g));
        memset(d, 0, sizeof(d));
        memset(v, 0, sizeof(v));
        for (auto t : s)
            for (auto c : t)
                v[c - 'a'] = 1;
        for (int i = 0; i < 26; ++i)
            if (v[i])   ++m;
        for (int i = 0; i < n - 1; ++i) {
            string a = s[i], b = s[i + 1];
            int j;
            for (j = 0; j < a.size(); ++j)
                if (a[j] != b[j])   break;
            if (j != a.size() && !g[a[j] - 'a'][b[j] - 'a']) g[a[j] - 'a'][b[j] - 'a'] = 1, ++d[b[j] - 'a']; 
        }
        string ans = "";
        while (q.size())    q.pop();
        for (int i = 0; i < 26; ++i)
            if (v[i] && !d[i])
                q.push(i);
        for (int i = 1; i <= m; ++i) {
            if (!q.size())  return "";
            int c = q.front();
            q.pop();
            ans += 'a' + c;
            for (int j = 0; j < 26; ++j) {
                if (g[c][j]) {
                    --d[j];
                    if (d[j] == 0)  q.push(j);
                }
            }
        }
        if (q.size())   ans = "";
        return ans;
    }
};