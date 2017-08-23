#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 2e5 + 5, M = 1e9 + 7;
LL dp[N];
LL inv[N], fac[N], rfac[N];
struct data {
	int x, y;
}a[N];
bool cmp(const data &p, const data &q) {
	if (p.x != q.x)	return p.x < q.x;
	else return p.y < q.y;
}
void init(){
	inv[0] = inv[1] = fac[0] = fac[1] = rfac[0] = rfac[1] = 1ll;
	for(int i = 2; i < N; ++i){
		inv[i] = (M - M / i) * inv[M % i] % M;
		fac[i] = fac[i - 1] * i % M;
		rfac[i] = rfac[i - 1] * inv[i] % M;
	}
}
LL C (int x, int y){
	return (fac[x] * rfac[y] % M) * rfac[x - y] % M;
}
int main() {
	int h, w, n;
	init();
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 1; i <= n; ++i)	scanf("%d%d", &a[i].x, &a[i].y);
	a[n + 1].x = h, a[++n].y = w;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		int x = a[i].x - 1;
		int y = a[i].y - 1;
		dp[i] = C(x + y, x);
		LL tt = 0;
		for (int j = 1; j < i; ++j) {
			if (a[i].x >= a[j].x && a[i].y >= a[j].y) {
				x = a[i].x - a[j].x;
				y = a[i].y - a[j].y;
				LL now = C(x + y, x);
				now = dp[j] * now % M;
				(tt += now) %= M;
			}
		}
		dp[i] -= tt;
		dp[i] = (dp[i] + M) % M;
	}
	cout << dp[n] << endl;
	return 0;
}
