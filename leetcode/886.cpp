#define F first
#define S second
#define pb push_back
#define mp make_pair
const int inf = 1e9;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        priority_queue<pair<int, int> > pq;
        vector<vector<pair<int, int> > > g(N + 1);
        vector<int> dis(N + 1, inf);
        vector<bool> vis(N + 1, 0);
        for (auto e: edges) {
            g[e[0]].pb(mp(e[2] + 1, e[1]));
            g[e[1]].pb(mp(e[2] + 1, e[0]));
        }
        dis[0] = 0;
        pq.push(mp(0, 0));
        while (pq.size()) {
            int u = pq.top().S;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto p: g[u]) {
                if (dis[u] + p.F < dis[p.S]) {
                    dis[p.S] = dis[u] + p.F;
                    pq.push(mp(-dis[p.S], p.S));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i)
            ans += dis[i] <= M;
        for (auto e: edges) {
            int u = e[0], v = e[1], w = e[2];
            int now = 0;
            if (dis[u] < M) {
                now += min(w, M - dis[u]);
            }
            if (dis[v] < M) {
                now += min(w, M - dis[v]);
            }
            now = min(now, w);
            ans += now;
        }
        return ans;
    }
};
