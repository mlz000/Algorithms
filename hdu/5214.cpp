#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 10000005;
const unsigned INF = -1u;
int n, c1, c2, c3;
unsigned l[MAXN], r[MAXN], a, b, c, d;
void work() {
    unsigned minr;
    minr = INF;
    c1 = -1;
    for (int i = 1; i <= n; ++i) {
        if (r[i] <= minr) minr = r[i], c1 = i;
    }
    minr = INF;
    c2 = -1;
    for (int i = 1; i <= n; ++i) {
        if (l[i] > r[c1] && r[i] <= minr) minr = r[i], c2 = i;
    }
    if (c2 == -1) {
        puts("NO");
        return;
    }
    minr = INF;
    c3 = -1;
    for (int i = 1; i <= n; ++i) {
        if (l[i] > r[c2] && r[i] <= minr) minr = r[i], c3 = i;
    }
    if (c3 == -1) {
        puts("NO");
        return;
    }
    puts("YES");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d%d%d", &n, &l[1], &r[1], &a, &b, &c, &d);
        for (int i = 2; i <= n; ++i) {
            l[i] = l[i - 1] * a + b;
            r[i] = r[i - 1] * c + d;
        }
        for (int i = 1; i <= n; ++i) {
            if (l[i] > r[i]) swap(l[i], r[i]);
        }
        work();
    }
    return 0;
}

