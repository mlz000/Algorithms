#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 10, M = 30;
int n, tot, ans, fr[M << 1], to[M << 1], du[N], co[N];
void add(int u, int v) {
    fr[tot] = u, to[tot++] = v;
}
void dfs(int x, int m, int now) {
    if (now > m / 2)    return;
    if (now + m - x + 1 < m / 2)    return;
    if (x == m + 1) {
        if (now != m / 2)    return;
        bool f = 1;
        for (int i = 1; i <= n; ++i)
            if (co[i] != du[i] / 2)    f = 0;
        if (f)    ++ans;
        return;
    }    
    ++co[fr[x]], ++co[to[x]];
    if (co[fr[x]] <= du[fr[x]] / 2 && co[to[x]] <= du[to[x]] / 2)    dfs(x + 1, m, now + 1);
    --co[fr[x]], --co[to[x]];
    dfs(x + 1, m, now);
}
int main() {
    int T, m;
    read(T);
    while (T--) {
        memset(co, 0, sizeof(co));
        memset(du, 0, sizeof(du));
        read(n), read(m);
        tot = 1;
        ans = 0;
        for (int i = 1, x, y; i <= m; ++i) {
            read(x), read(y);
            add(x, y);
            ++du[x], ++du[y];
        }
        bool f = 1;
        for (int i = 1; i <= n; ++i)
            if (du[i] & 1)    f = 0;
        if (f)    dfs(1, m, 0);
        cout << ans << endl;
    }
    return 0;
}
