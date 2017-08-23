#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
const int N = 45;
set<ll> s;
ll a[N];
int T, n;
int calc(int l, int r, int m) {
	ll d = (a[r]-a[l])/m;
	int ans = 0;
	if (d == 0) {
		for (int i = 0; i < n; i++)
			if (a[i] != a[l]) ans++;
		return ans;
	}
	for (int i = 1; i < n; i++)
		if (!s.count(a[l]+i*d)) ans++;
	return ans;
}
int main() {
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		scanf("%d", &n);
		s.clear();
		for (int i = 0; i < n; i++) {
			scanf("%lld", a+i);
			s.insert(a[i]);
		}
		sort(a, a+n);
		int ans = n;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				for (int k = 1; k < n; k++) {
					if ((a[j]-a[i])%k != 0) continue;
					ans = min(ans, calc(i, j, k));
				}
		if (n == 1) ans = 0;
		printf("Case #%d: %d\n", C, ans);
	}
	return 0;
}
