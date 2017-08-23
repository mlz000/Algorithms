#include <bits/stdc++.h>//mobius
using namespace std;
typedef long long LL;
#define pb push_back
const int N = 1e5 + 5, M = 258280327;
LL inv[N], fac[N], rfac[N];
int n, mx, tot, a[N], p[N], pw[N], mu[N], cnt[N], F1[N], f1[N], F2[N], f2[N];
bool check[N];
vector<int> divsor[N];
void init(){
	inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1ll;
	for(int i = 2; i < N; ++i){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fac[i] = fac[i - 1] * i % M;
		rfac[i] = rfac[i - 1] * inv[i] % M;
	}
	mu[1] = 1;
	for (int i = 2; i <= 100000; ++i){
		if(!check[i])	p[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot; ++j){
			if (i * p[j] > 100000)	break;
			check[i * p[j]] = 1;
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			else mu[i * p[j]] = -mu[i];
		}
	}
	pw[0] = 1;
	for (int i = 1; i <= 100000; ++i) {
		for (int j = i; j <= 100000; j += i)
			divsor[j].pb(i);
		pw[i] = (LL)pw[i - 1] * 2 % M;
	}
}
inline int A(int x, int y) {
	return fac[x] * rfac[x - y] % M;
}
void gao() {
	for (int i = 1; i <= mx; ++i)	F1[i] = F2[i] = f1[i] = f2[i] = 0;
	for (int i = 1; i <= mx; ++i) 
		for (int j = 1; j <= cnt[i]; ++j) {
			(F1[i] += fac[n - j + 1] * A(cnt[i], j) % M) %= M;
			F2[i] = (LL)cnt[i] * pw[cnt[i] - 1] % M;
		}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= mx; ++i) {
		for (int j = i; j <= mx; j += i) {
			(f1[i] += (F1[j] * mu[j / i] + M) % M) %= M;
			(f2[i] += (F2[j] * mu[j / i] + M) % M) %= M;			
		}
		(ans1 += (LL)f1[i] * i % M) %= M;
		(ans2 += (LL)f2[i] * i % M) %= M;
	}
	if (ans1 > ans2) printf("Mr. Zstu %d\n", ans1);
	else if (ans1 == ans2) printf("Equal %d\n", ans1);
	else printf("Mr. Hdu %d\n", ans2);
}
int main() {
	init();
	while (~scanf("%d", &n)) {
		memset(cnt, 0, sizeof(cnt));
		mx = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			mx = max(mx, a[i]);
			for (int j = 0; j < divsor[a[i]].size(); ++j)	++cnt[divsor[a[i]][j]];
		}
		gao();
	}
	return 0;
}
