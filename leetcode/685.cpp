const int N = 1005;
bool vis[N];
int f[N];
class Solution {
public:
    void init() {
        for (int i = 1; i < N; ++i) f[i] = i;
        memset(vis, 0, sizeof(vis));   
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = n - 1; i >= 0; --i) {
            init();
            bool ok = 1;
            int rt = -1;;
            for (int j = 0; j < n; ++j)
                if (j != i) {
                    int u = edges[j][0], v = edges[j][1];
                    if (rt == -1)   rt = u;
                    vis[u] = vis[v] = 1;
                    if (u == v) ok = 0;
                    if (find(u) == find(v) || find(v) != v) ok = 0;
                    else f[find(v)] = find(u);
                }
            for (int i = 1; i < N; ++i)
                if (vis[i] && find(i) != find(rt))  ok = 0;
            if (ok) return edges[i];
        }
    }
};