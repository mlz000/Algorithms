class Solution {
public:
    vector<int> f;
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> d(n);
        f.resize(n);
        for (int i = 0; i < n; ++i)   f[i] = i;
        bool ok = 1;
        for (auto e : edges) {
            int fa = find(f[e.first]);
            int fb = find(f[e.second]);
            ++d[e.first], ++d[e.second];
            if (fa == fb)   ok = 0;
            f[fa] = fb;
        }
        int rt = 0;
        for (int i = 0; i < n; ++i)
            if (find(i) == i)  ++rt;
        if (rt != 1)    ok = 0;
        return ok;
    }
};