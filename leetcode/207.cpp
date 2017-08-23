#define pb push_back
class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>>& a) {
        int m = a.size();
        in.resize(n), G.resize(n);
        for (auto t : a) {
            G[t.second].pb(t.first);
            ++in[t.first];
        }
        for (int i = 0; i < n; ++i)
            if (!in[i]) q.push(i);
        while (q.size()) {
            int t = q.front();
            q.pop();
            ans.pb(t);
            for (auto v : G[t]) {
                --in[v];
                if (!in[v])    q.push(v);
            }
        }
        if (ans.size() != n)    return 0;
        return 1;
    }
private:
    vector<int> in, ans;
    vector<vector<int> > G;
    queue<int> q;
};