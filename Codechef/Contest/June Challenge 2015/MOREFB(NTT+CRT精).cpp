#include <bits/stdc++.h>//NTT + crt
using namespace std;
const int P = 99991, Q = 10104, A = 55048, B = 44944;
const int P1 = 998244353, G1 = 3;//P1 = ((7 * 17) << 23) + 1
const int P2 = 995622913, G2 = 5;//P2 = ((3 * 3 * 211) << 19) + 1
const long long M1 = 397550359381069386LL, M2 = 596324591238590904LL, MM = 993874950619660289LL;//MM = P1*P2
const int M = 1 << 16;//g为原根
typedef long long LL;
typedef long long Complex;
int num[M + 5], x[M + 5], y[M + 5];
int K, po, a[2][M + 5], aa[2][M + 5], b[2][M + 5], bb[2][M + 5], c[2][M + 5], cc[2][M + 5], w[M + 5], temp[M + 5];
int inv[6][20], ww[6][20], iww[6][20];
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
inline int crt(int x, int y) {
	return (mul(M1, x, MM) + mul(M2, y, MM)) % MM % P;
}
void init() {
	for (int i = 0; i <= 16; ++i) {
		inv[3][i] = gao(1 << i, P1 - 2, P1);
		inv[5][i] = gao(1 << i, P2 - 2, P2);
		ww[3][i] = gao(3, (P1 - 1) / (1 << i + 1), P1);
		ww[5][i] = gao(5, (P2 - 1) / (1 << i + 1), P2);
		iww[3][i] = gao(ww[3][i], P1 - 2, P1);
		iww[5][i] = gao(ww[5][i], P2 - 2, P2);
	}
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
void calc(int l, int r) {
	if (l == r) {
		x[0] = y[0] = 1;
		x[1] = gao(A, num[l], P), y[1] = gao(B, num[l], P);
		return;
	}
	int mid = l + r >> 1;
	int k = 1;
	int len = min(max(mid - l + 1, r - mid), K) + 1;
	int t = 0;
	while (len * 2 > k)	k <<= 1, ++t;
	int **L, **R;
	L = new int*[2], R = new int*[2];
	for (int i = 0; i < 2; ++i) L[i] = new int[k], R[i] = new int[k];
	calc(l, mid);
	for (int i = 0; i <= min(mid - l + 1, K); ++i)	L[0][i] = x[i], L[1][i] = y[i];
	calc(mid + 1, r);
	po = t;
	for (int i = 0; i <= min(r - mid, K); ++i)	R[0][i] = x[i], R[1][i] = y[i];
	for (int i = 0; i < k; ++i)	a[0][i] = a[1][i] = aa[0][i] = aa[1][i] = 0;
	for (int i = 0; i < k; ++i)	b[0][i] = b[1][i] = bb[0][i] = bb[1][i] = 0;
	for (int i = 0; i <= min(mid - l + 1, K); ++i)	a[0][i] = a[1][i] = L[0][i], aa[0][i] = aa[1][i] = L[1][i];
	for (int i = 0; i <= min(r - mid, K); ++i)	b[0][i] = b[1][i] = R[0][i], bb[0][i] = bb[1][i] = R[1][i];
	NTT(a[0], k, 1, G1, P1), NTT(a[1], k, 1, G2, P2);
	NTT(aa[0], k, 1, G1, P1), NTT(aa[1], k, 1, G2, P2);
	NTT(b[0], k, 1, G1, P1), NTT(b[1], k, 1, G2, P2);
	NTT(bb[0], k, 1, G1, P1), NTT(bb[1], k, 1, G2, P2);
	for (int i = 0; i < k; ++i) {
		c[0][i] = (LL)a[0][i] * b[0][i] % P1, c[1][i] = (LL)a[1][i] * b[1][i] % P2;
		cc[0][i] = (LL)aa[0][i] * bb[0][i] % P1, cc[1][i] = (LL)aa[1][i] * bb[1][i] % P2;
	}
	NTT(c[0], k, -1, G1, P1), NTT(c[1], k, -1, G2, P2);
	NTT(cc[0], k, -1, G1, P1), NTT(cc[1], k, -1, G2, P2);
	for (int i = 0; i < min(k, K + 1); ++i) {
		x[i] = crt(c[0][i], c[1][i]) % P;
		y[i] = crt(cc[0][i], cc[1][i]) % P;
	}
}
int main() {
	int n;
	init();
	clock_t st, ed;
	st = clock();
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; ++i)	scanf("%d", &num[i]), num[i] %= 33330;
	calc(1, n);//分治
	printf("%d\n", (LL)(x[K] - y[K] + P) * 22019 % P);
	ed = clock();
	return 0;
}

