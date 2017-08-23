#include <bits/stdc++.h>//c[n + m][n] -1
using namespace std;
typedef long long LL;
const int N = 105, M = 1e6 + 3;
int T;
LL n, inv[M], fac[M], rfac[M];
void init(){
	inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1ll;
	for(int i = 2; i < M; ++i){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fac[i] = fac[i - 1] * i % M;
		rfac[i] = rfac[i - 1] * inv[i] % M;
	}
}
LL P(LL x, LL y) {
	LL t = 1ll;
	for (; y; y >>= 1) {
		if (y & 1ll)	t = t * x % M;
		x = x * x % M;
	}
	return t;
}
LL lucas(LL x, LL y) {  
    LL ans = 1;  
    while(x && y) {  
        LL a = x % M;  
        LL b = y % M;  
        if(a < b) return 0;  
        ans = (ans * fac[a] * P(fac[b] * fac[a - b] % M, M - 2)) % M;
        x /= M;  
        y /= M;  
    }  
    return ans;  
} 	
int main() {
	init();
	scanf("%d", &T);
	while (T--) {
		LL l, r;
		scanf("%lld%lld%lld", &n, &l, &r);
		LL m = r - l + 1;
		printf("%lld\n", (lucas(n + m, min(n, m)) - 1 + M) % M);
	}
	return 0;
}
