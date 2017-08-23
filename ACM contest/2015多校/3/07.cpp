#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
const int N = 1e5 + 5, M = 998244353;
LL inv[N], fac[N], rfac[N];
int dp[N], a, b, c;
void init(){
	inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1ll;
	for(int i = 2; i < N; ++i){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fac[i] = fac[i - 1] * i % M;
		rfac[i] = rfac[i - 1] * inv[i] % M;
	}
	dp[0] = a = 1;
	for (int i = 1; i <= 1e5; ++i) {
		dp[i] = fac[i - 1] * (((LL)i * i % M * a % M - 2ll * i * b % M + c + M) % M) % M;
		(a += rfac[i] * dp[i] % M) %= M;
		(b += rfac[i] * dp[i] % M * i % M) %= M;
		(c += rfac[i] * dp[i] % M * i % M * i % M) %= M;
	}
}
int main() {
	init();
	int n;
	while (~scanf("%d", &n)) {
		printf("%d\n", dp[n]);
	}
	return 0;
}
