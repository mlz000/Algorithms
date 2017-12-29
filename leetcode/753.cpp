class Solution {
public:
    char s[10000];
    bool vis[10000];
    int n, k;
    string ans;
    bool dfs(int p, int now, int tot) {
        if (p == tot + n - 1) {
            for (int i = 0; i < tot + n - 1; ++i)   ans += s[i];
            return 1;
        }
        for (int i = 0; i < k; ++i) {
            int t = now * k + i;
            if (!vis[t]) {
                vis[t] = 1;
                s[p] = '0' + i;
                if (dfs(p + 1, t % (tot / k), tot))   return 1;
                s[p] = '0';
                vis[t] = 0;
            }
        }
        return 0;
    }
    
    string crackSafe(int n, int k) {
        this -> n = n, this -> k = k;
        int tot = pow(k, n);
        ans = "";
        for (int i = 0; i < n - 1; ++i) s[i] = '0';
        dfs(n - 1, 0, tot);
        return ans;
    }
};