#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 10005;
const int L = 65;
char s[L];
ll x[N];
int T, n, k;
int main() {
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			x[i] = 0;
			for (int j = 0; j < k; j++) x[i] = x[i]*2+s[j]-'0';
		}
		if (n == 1) { printf("Case #%d: %d\n", C, 0); continue; }
		sort(x, x+n);
		ll a = x[0], b = x[1], c = x[n-2], d = x[n-1];
		ll X = (1ll<<k)-1;
		ll ans = max(c+d-X, X-a-b);
		ans = max(ans, d-a);
		printf("Case #%d: %lld\n", C, ans);
	}
	return 0;
}
