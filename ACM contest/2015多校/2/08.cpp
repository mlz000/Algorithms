#include <bits/stdc++.h>//FFT
using namespace std;
typedef long long LL;
const LL P = 50000000001507329LL;
const int N = 1e5 + 5, M = 1 << 17;//gÎªÔ­¸ù
int x[N], sum[N];
int po;
LL a[M + 5], b[M + 5], c[M + 5], w[M + 5], temp[M + 5], pr[M + 5];
LL inv[4][20], ww[4][20], iww[4][20];
LL mul(LL x, LL y) {
    return (x * y - (LL)(x / (long double)P * y + 1e-3) * P + P) % P;
}
LL gao(LL x, LL y, LL mod) {
    LL t = 1;
    for (; y; y >>= 1) {
        if (y & 1)    t = mul(t, x);
        x = mul(x, x);
    }
    return t;
}
void init() {
    for (int i = 0; i <= 17; ++i) {
        inv[3][i] = gao(1 << i, P - 2, P);
        ww[3][i] = gao(3, (P - 1) / (1 << i + 1), P);
        iww[3][i] = gao(ww[3][i], P - 2, P);
    }
    pr[0] = 0;
    for (int i = 1; i < N; i++)
        pr[i] = pr[i - 1] + (LL)i * (i + 1) / 2;
}
inline void NTT(LL y[], int n, int rev, int g, LL mod) {
    LL wn, w, t;
    LL invv = inv[g][po];
    for (int i = 1, j, k, t; i < n; ++i) {
        for (j = 0, k = n >> 1, t = i; k; k >>= 1, t >>= 1) j = j << 1 | t & 1 ;
        if (i < j) swap(y[i], y[j]);
    }
    for (int s = 2, ds = 1, k, i, j = 0; s <= n; ds = s, s <<= 1, ++j) {
        wn = ww[g][j];
        if (rev == -1)    wn = iww[g][j];
        for (k = 0; k < n; k += s) {
            for (i = k, w = 1; i < k + ds; ++i, w = mul(w, wn)) {
                y[i + ds] = (y[i] - (t = mul(w, y[i + ds])) + mod) % mod;
                y[i] = (y[i] + t) % mod;
            }
        }
    }
    if (rev == -1) for (int i = 0; i < n; ++ i ) y[i] = mul(y[i], invv);
} 
int main() {
    init();
    int n, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)    scanf("%d", &x[i]), sum[i] = sum[i - 1] + x[i];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i)    a[sum[i]] += i, ++b[sum[n] - sum[i - 1]];
        po = 0;
        int k = 1;
        while (sum[n] * 2 + 1 > k)    k <<= 1, ++po;
        NTT(a, k, 1, 3, P), NTT(b, k, 1, 3, P);
        for (int i = 0; i < k; ++i)    a[i] = mul(a[i], b[i]);
        NTT(a, k, -1, 3, P);
        for (int i = 1; i <= sum[n]; ++i)    c[i] = a[sum[n] + i];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i)    ++a[sum[i]], b[sum[n] - sum[i - 1]] += i - 1;
        NTT(a, k, 1, 3, P), NTT(b, k, 1, 3, P);
        for (int i = 0; i < k; ++i)    a[i] = mul(a[i], b[i]);
        NTT(a, k, -1, 3, P);
        for (int i = 1; i <= sum[n]; ++i)    c[i] = (c[i] - a[sum[n] + i] + P) % P;
        c[0] = 0;
        for (int i = 1, z = 0; i <= n + 1; ++i) {
            if (i == n + 1 || x[i])
                c[0] += pr[z], z = 0;
            else
                z++;
        }  
        for (int i = 0; i <= sum[n]; ++i)    cout << c[i] << endl;
    }
    return 0;
}
