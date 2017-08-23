#define pb push_back
class Solution {
public:
    unordered_map<int, vector<int> > G;
    unordered_map<int, int> cnt;
    unordered_map<int, bool> vis;
    int hash(int a, int b, int c, int d) {
        return a * 13331 + b * 131 + c * 67 + d * 7;
    }
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int> > ans;
        int n = a.size();
        if (!n) return ans;
        for (auto x : a)    ++cnt[x];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int x = target - a[i] - a[j];
                if (G.find(x) != G.end()) {
                    for (auto t : G[x]) {
                        vector<int> now;
                        unordered_map<int, int> tmp;
                        now.pb(a[i]), now.pb(a[j]), now.pb(t), now.pb(x - t);
                        ++tmp[a[i]], ++tmp[a[j]], ++tmp[t], ++tmp[x - t];
                        if (tmp[a[i]] > cnt[a[i]] || tmp[a[j]] > cnt[a[j]] || tmp[t] > cnt[t] || tmp[x - t] > cnt[x - t])   continue;
                        sort(now.begin(), now.end());
                        int v = hash(now[0], now[1], now[2], now[3]);
                        if (vis.find(v) == vis.end()) {
                            vis[v] = 1;
                            ans.pb(now);
                        }
                    }
                }
                G[a[i] + a[j]].pb(a[i]);
            }
        return ans;
    }
};