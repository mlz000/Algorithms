#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 1e6 + 5;
int n, c[100000];
LL ans, a[N];
vector<LL> g;
void work(LL x) {
    g.clear();
    for (LL i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            g.pb(i);
            if (i * i != x) g.pb(x / i);
        }
    }
    sort(g.begin(), g.end());
    for (int i = 0; i < g.size(); ++i)  c[i] = 0;
    for (int i = 1; i <= n; ++i)
        ++c[lower_bound(g.begin(), g.end(), __gcd(a[i], x)) - g.begin()];
    for (int i = 0; i < g.size(); ++i)
        for (int j = i + 1; j < g.size(); ++j)
            if (g[j] % g[i] == 0)   c[i] += c[j];
    for (int i = 0; i < g.size(); ++i)
        if (c[i] * 2 >= n)  ans = max(ans, g[i]);
}
int main() {
    srand(time(0));
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)    scanf("%I64d", &a[i]);
    for (int i = 1; i <= 10; ++i)   work(a[rand() * rand() % n + 1]);
    printf("%I64d\n", ans);
    return 0;
}

