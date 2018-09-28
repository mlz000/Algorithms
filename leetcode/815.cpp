class Solution {
public:
    unordered_map<int, bool> G[505];
    unordered_map<int, unordered_set<int> > p;
    int d[505][505], step[505];
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        memset(d, 0x3f, sizeof(d));
        for (int i = 0; i < routes.size(); ++i) {
            for (auto x : routes[i]) {
                G[i][x] = true;
                p[x].insert(i);
            }
            d[i][i] = 0;
        }
        for (int i = 0; i < routes.size(); ++i)
            for (int j = i + 1; j < routes.size(); ++j)
                for (auto x : routes[i]) {
                    if (G[j].find(x) != G[j].end()) {
                        d[i][j] = d[j][i] = 1;
                    }
                }
        for (int k = 0; k < routes.size(); ++k)
            for (int i = 0; i < routes.size(); ++i)
                for (int j = 0; j < routes.size(); ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int ans = INT_MAX;
        for (auto x : p[S])
            for (auto y : p[T])
                ans = min(ans, d[x][y]);
        if (ans > 500) ans = -2;
        return ans + 1;
    }
};