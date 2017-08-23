#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5, M = 26;
int c[N][M], dep[N], ans[N];
char s[5];
void dfs(int u, int d) {
    dep[u] = d;
    for (int i = 0; i < M; ++i)
        if (c[u][i])
            dfs(c[u][i], d + 1);
}
int gao(vector<int> a) {
    if (a.size() <= 1) return 0;
    int t = a.size() - 1;
    for (int j = 0; j < M; ++j) {
        vector<int> b;
        for (int i = 0; i < a.size(); ++i)
            if (c[a[i]][j]) b.pb(c[a[i]][j]);
        t += gao(b);
    }
    return t;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d%s", &u, &v, s);
        c[u][s[0] - 'a'] = v;
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        vector<int> a;
        for (int j = 0; j < M; ++j)
            if (c[i][j])    a.pb(c[i][j]);
        if (a.size() > 0)   ans[dep[i] + 1] += gao(a) + 1;
    }
    int mx = 0, p;
    for (int i = 1; i <= n; ++i)
        if (ans[i] > mx)
            mx = ans[i], p = i;
    printf("%d\n%d\n", n - mx, p);
    return 0;
}
