class Solution {
public:
    stack<char> s;
    bool vis[10000][10];
    int n, k;
    string ans;
    void dfs(int now, int tot) {
        for (int i = 0; i < k; ++i) {
            int t = (now * k + i) % (tot / k);
            if (now == 0 && i == 0) continue;
            if (!vis[now][i]) {
                vis[now][i] = 1;
                dfs(t, tot);
            }
        }
        s.push('0' + (now % k));
    }
    
    string crackSafe(int n, int k) {
        this -> n = n, this -> k = k;
        int tot = pow(k, n);
        for (int i = 0; i < n - 1; ++i) ans += '0';
        if (n == 1) for (int i = 0; i < k; ++i) s.push('0' + i);
        else dfs(0, tot);
        while (s.size())    ans += s.top(), s.pop();
        return ans;
    }
};