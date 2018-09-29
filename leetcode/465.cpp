class Solution {
public:
    unordered_map<int, long long> G;
    vector<int> mo;
    int ans;
    void dfs(int p, int res) {
        while (p < mo.size() && !mo[p]) ++p;
        if (p >= mo.size()) {
            ans = min(ans, res);
            return;
        }
        for (int i = p + 1, last = 0; i < mo.size(); ++i) {
            if (mo[i] != last && mo[i] * mo[p] < 0) {
                mo[i] += mo[p];
                dfs(p + 1, res + 1);
                last = mo[p];
                mo[i] -= mo[p];
            }
        }
    }
    int minTransfers(vector<vector<int>>& t) {
        for (auto a: t) {
            G[a[0]] += a[2];
            G[a[1]] -= a[2];
        }
        for (auto it : G) {
            if (it.second)   mo.push_back(it.second);
        }
        ans = INT_MAX;
        dfs(0, 0);
        return ans;
    }
};