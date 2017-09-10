typedef pair<int, int> pii;
#define mp make_pair
#define F first
#define S second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, step[51][51];
vector<pair<int, pii > > G;
vector<vector<int>> gg;
queue<pii> q;
class Solution {
public:
    int bfs(pii a, pii b) {
        memset(step, 0, sizeof(step));
        while (q.size())    q.pop();
        q.push(a);
        while (q.size()) {
            pii t = q.front();
            q.pop();
            if (t.F == b.F && t.S == b.S)   return step[t.F][t.S];
            for (int i = 0; i < 4; ++i) {
                int x = t.F + dx[i];
                int y = t.S + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !step[x][y] && gg[x][y] > 0) {
                    step[x][y] = step[t.F][t.S] + 1;
                    q.push(mp(x, y));
                }
            }
        }
        return -1;
    }
    int cutOffTree(
        vector<vector<int>> & a) {
        gg = a;
        n = a.size(), m = a[0].size();
        G.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] > 1)
                    G.push_back(make_pair(a[i][j], make_pair(i, j)));
        sort(G.begin(), G.end());
        int ans = 0, p = 0;
        pii now = mp(0, 0);
        while (p != G.size()) {
            int t = bfs(now, G[p].S);
            if (t == -1)    return t;
            ans += t;
            now = G[p].S;
            ++p;
        }
        return ans;
    }
};