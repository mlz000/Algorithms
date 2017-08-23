#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 1e9 + 7;
typedef long long LL;
LL inv[N], fac[N], rfac[N];
LL P(LL x, LL y) {
	LL t = 1;
	for (; y; y >>= 1) {
		if (y & 1)	t = t * x % M;
		x = x * x % M;
	}
	return t;
}
LL C(int n, int m) {
	return fac[n] * rfac[m] % M * rfac[n - m] % M;
}
void init(){
	inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1ll;
	for(int i = 2; i < N; ++i){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fac[i] = fac[i - 1] * i % M;
		rfac[i] = rfac[i - 1] * inv[i] % M;
	}
}
LL gao(int f, int w, int h) {
	LL now = 0ll;
	if (!w)	return 1;
	for (int i = 1; i <= f + 1 && i * (h + 1) <= w; ++i) {
		(now += C(w - i * h - 1, i - 1) * C(f + 1, i)) %= M;
	}
	return now;
}
int main() {
	init();
	int f, w, h;
	scanf("%d%d%d", &f, &w, &h);
	printf("%I64d\n", gao(f, w, h) * P(gao(f, w, 0), M - 2) % M);
	return 0;
}
