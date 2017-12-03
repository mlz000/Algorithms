class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        vector<int> ans;
        unordered_map<int, int> G;
        for (int i = a.size() - 1; i >= 0; --i) {
            if (i == a.size() - 1)  ans.push_back(0), G[a[i]] = i;
            else {
                int p = 1e5;
                for (int j = a[i] + 1; j <= 100; ++j)
                    if (G.count(j)) p = min(p, G[j]);
                if (p == 1e5)   ans.push_back(0);
                else ans.push_back(p - i);
                if (!G.count(a[i]))  G[a[i]] = i;
                else G[a[i]] = min(G[a[i]], i);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};