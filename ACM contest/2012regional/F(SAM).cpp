#include <cstdio>//SAM
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100050 << 1, M = 2012;
int n, tot, last, step[N], son[N][11], par[N], cnt[N], q[N], sum[N], ans[N];
char s[N >> 1];
void add(int x, int l) {
    int p = last, np = ++tot;
    step[p] = l, last = np;
    for (; !son[p][x] && ~p; p = par[p])    son[p][x] = np;
    if (p == -1)    return;
    int q = son[p][x];
    if (step[q] == step[p] + 1)    par[np] = q;
    else {
        step[++tot] = step[p] + 1;
        int nq = tot;
        memcpy(son[nq], son[q], sizeof(son[q]));
        par[nq] = par[q];
        par[np] = par[q] = nq;
        for (; son[p][x] == q && ~p; p = par[p])    son[p][x] = nq;
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        tot = last = 0;
        int l = 0;
        memset(sum, 0, sizeof(sum));
        memset(ans, 0, sizeof(ans));
        memset(cnt, 0, sizeof(cnt));
        memset(par, 0, sizeof(par));
		memset(son, 0, sizeof(son));
        par[0] = -1;
        while (n--) {
            scanf("%s", s);
            for (int i = 0; s[i]; ++i)    add(s[i] - '0', ++l);
            add(10, ++l);
        }    
        for (int i = 1; i <= tot; ++i)    ++cnt[step[i]];
        for (int i = 1; i <= tot; ++i)    cnt[i] += cnt[i - 1];
        for (int i = 1; i <= tot; ++i)    q[cnt[step[i]]--] = i;
        sum[0] = 1;
        for (int i = 0; i <= tot; ++i) {
            int u = q[i];
            for (int j = 0; j < 10; ++j) {
                if ((!i && !j) || !son[u][j])    continue;
                int v = son[u][j];
                (sum[v] += sum[u]) %= M;
                (ans[v] += (sum[u] * j % M) + (ans[u] * 10 % M)) %= M;
            }
        }
        int t = 0;
        for (int i = 1; i <= tot; ++i)    (t += ans[i]) %= M;
        printf("%d\n", t);
    }
    return 0;
}
