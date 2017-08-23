#include <bits/stdc++.h>
using namespace std;
const int N = 405, M = N * N;
int d[N][N];
#define pb push_back
vector<int> g[N];
struct data {
    int x, y;
    data(){}
    data(int x, int y): x(x), y(y){}
}e[M];
int main() {
    freopen("defence.in", "r", stdin);
    freopen("defence.out", "w", stdout);
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(d, 0x3f, sizeof(d));
    for (int i = 1, x, y; i <= m; ++i) {
        scanf("%d%d", &x, &y);
        e[i] = data(x, y);
        d[x][y] = d[y][x] = 1;
    }
    for (int i = 1; i <= n; ++i)    d[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = d[s][t];
    for (int i = 1; i <= m; ++i) {
        int x = e[i].x, y = e[i].y;
        int tt = max(d[s][x], d[s][y]);
        if (tt <= ans)  g[tt].pb(i);
        else g[ans].pb(i);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; ++i) {
        printf("%d ", g[i].size());
        for (int j = 0; j < g[i].size(); ++j)   printf("%d ", g[i][j]);
        puts("");
    }
    return 0;
}
