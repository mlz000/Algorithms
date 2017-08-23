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
const int N = 25;
int n, m, pos[N];
double a[N], sum[N];
int main() {
    srand(65535);
    read(n), read(m);
    double avg = 0.0;
    for (int i = 1; i <= n; ++i) scanf("%lf", &a[i]), avg += a[i];
    random_shuffle(a + 1, a + n + 1);
    avg /= m;
    double t = 1e20;
    for (int i = 1; i <= 3000; ++i) {
        memset(sum, 0, sizeof(sum));
        double ans = 0;
        for (int j = 1; j <= n; ++j) pos[j] = rand() % m + 1, sum[pos[j]] += a[j];
        for (int j = 1; j <= m; ++j) ans += (sum[j] - avg) * (sum[j] - avg);
        for (double T = 2000; T >= 0.1; T *= 0.9) {
            int x = rand() % n + 1, p = pos[x], y;
            if (T > 500) y = min_element(sum + 1, sum + m + 1) - sum;
            else y = rand() % m + 1;
            if (p == y) continue;
            double pre = ans;
            ans -= (sum[p] - avg) * (sum[p] - avg);
            ans += (sum[p] - a[x] - avg) * (sum[p] - a[x] - avg);
            ans -= (sum[y] - avg) * (sum[y] - avg);
            ans += (sum[y] + a[x] - avg) * (sum[y] + a[x] - avg);
            sum[p] -= a[x], sum[y] += a[x];
            t = min(t, ans);
            if (ans <= pre)  pos[x] = y;
            else sum[p] += a[x], sum[y] -= a[x], ans = pre;
        /*  else if (rand() >= exp((ans - pre) / T)) {
                sum[p] += a[x], sum[y] -= a[x];
                ans = pre;
            }
            else pos[x] = y;*/
        }
    }
    printf("%.2lf\n", sqrt(t / m));
    return 0;
}
