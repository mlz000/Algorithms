#define pb push_back
class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> nxt, dp;
    int dfs(int u) {
        if (nxt[u] == -1)   return dp[u] = 1;
        if (dp[u])  return dp[u];
        return dp[u] = dfs(nxt[u]) + 1;
    }
    int longestConsecutive(vector<int>& a) {
        int n = a.size();
        nxt.resize(n, -1), dp.resize(n, 0);
        for (int i = 0; i < n; ++i)
            if (mp.find(a[i]) == mp.end()) mp[a[i]] = i;
        for (int i = 0; i < n; ++i) {
            int t2 = (mp.find(a[i] + 1) == mp.end()) ? -1 : mp[a[i] + 1];
            if (~t2)    nxt[i] = t2;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) dfs(i);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};