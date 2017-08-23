#include <bits/stdc++.h>//NTT + CRT
using namespace std;
typedef long long LL;
const int N = 1e5 + 5, M = 1 << 17;//gÎªÔ­¸ù
int x[N], sum[N];
int po;
int a[2][M + 5], b[2][M + 5];
const int P1 = 998244353, G1 = 3;//P1 = ((7 * 17) << 23) + 1
const int P2 = 995622913, G2 = 5;//P2 = ((3 * 3 * 211) << 19) + 1
const LL M1 = 397550359381069386LL, M2 = 596324591238590904LL, MM = 993874950619660289LL;//MM = P1*P2
int inv[6][20], ww[6][20], iww[6][20];
LL ans[M + 5], c[M + 5], pr[M + 5];;
LL gao(LL x, LL y, int mod) {
	LL t = 1;
	for (; y; y >>= 1) {
		if (y & 1)	t = t * x % mod;
		x = x * x % mod;
	}
	return t;
}
inline LL mul(LL x, LL y, LL z){
	return (x * y - (LL)(x /(long double)z * y + 1e-3) * z + z ) % z;
}
inline LL crt(int x, int y) {
	return (mul(M1, x, MM) + mul(M2, y, MM)) % MM;
}
void init() {
	for (int i = 0; i <= 17; ++i) {
		inv[3][i] = gao(1 << i, P1 - 2, P1);
		inv[5][i] = gao(1 << i, P2 - 2, P2);
		ww[3][i] = gao(3, (P1 - 1) / (1 << i + 1), P1);
		ww[5][i] = gao(5, (P2 - 1) / (1 << i + 1), P2);
		iww[3][i] = gao(ww[3][i], P1 - 2, P1);
		iww[5][i] = gao(ww[5][i], P2 - 2, P2);
	}
	pr[0] = 0;
	for (int i = 1; i < N; i++)
		pr[i] = pr[i - 1] + (LL)i * (i + 1) / 2;
}
inline void NTT(int y[], int n, int rev, int g, int mod) {
    LL wn, w, t;
	LL invv = inv[g][po];
    for (int i = 1, j, k, t; i < n; ++i) {
        for (j = 0, k = n >> 1, t = i; k; k >>= 1, t >>= 1) j = j << 1 | t & 1 ;
        if (i < j) swap(y[i], y[j]);
    }
    for (int s = 2, ds = 1, k, i, j = 0; s <= n; ds = s, s <<= 1, ++j) {
        wn = ww[g][j];
        if (rev == -1)	wn = iww[g][j];
        for (k = 0; k < n; k += s) {
            for (i = k, w = 1; i < k + ds; ++ i, w = w * wn % mod) {
                y[i + ds] = (y[i] - (t = w * y[i + ds] % mod) + mod) % mod;
                y[i] = (y[i] + t) % mod;
            }
        }
    }
    if (rev == -1) for (int i = 0; i < n; ++ i ) y[i] = (LL)y[i] * invv % mod ;
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
        for (int i = 1; i <= n; ++i)    a[0][sum[i]] += i, a[1][sum[i]] += i, ++b[0][sum[n] - sum[i - 1]], ++b[1][sum[n] - sum[i - 1]];
        po = 0;
        int k = 1;
        while (sum[n] * 2 + 1 > k)    k <<= 1, ++po;
        NTT(a[0], k, 1, G1, P1), NTT(b[0], k, 1, G1, P1);
		NTT(a[1], k, 1, G2, P2), NTT(b[1], k, 1, G2, P2);
        for (int i = 0; i < k; ++i) {
			a[0][i] = (LL)a[0][i] * b[0][i] % P1;
			a[1][i] = (LL)a[1][i] * b[1][i] % P2;
		}
        NTT(a[0], k, -1, G1, P1), NTT(a[1], k, -1, G2, P2);
		for (int i = 0; i < k; ++i)	c[i] = crt(a[0][i], a[1][i]);
        for (int i = 1; i <= sum[n]; ++i)    ans[i] = c[sum[n] + i];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; ++i)    ++a[0][sum[i]], ++a[1][sum[i]], b[0][sum[n] - sum[i - 1]] += i - 1, b[1][sum[n] - sum[i - 1]] += i - 1;
        NTT(a[0], k, 1, G1, P1), NTT(b[0], k, 1, G1, P1);
		NTT(a[1], k, 1, G2, P2), NTT(b[1], k, 1, G2, P2);
        for (int i = 0; i < k; ++i) {
			a[0][i] = (LL)a[0][i] * b[0][i] % P1;
			a[1][i] = (LL)a[1][i] * b[1][i] % P2;
		}
        NTT(a[0], k, -1, G1, P1), NTT(a[1], k, -1, G2, P2);
		for (int i = 0; i < k; ++i)	c[i] = crt(a[0][i], a[1][i]);
        for (int i = 1; i <= sum[n]; ++i)    ans[i] = (ans[i] - c[sum[n] + i]);
        ans[0] = 0;
        for (int i = 1, z = 0; i <= n + 1; ++i) {
            if (i == n + 1 || x[i])
                ans[0] += pr[z], z = 0;
            else
                z++;
        }  
        for (int i = 0; i <= sum[n]; ++i)    cout << ans[i] << endl;
    }
    return 0;
}
