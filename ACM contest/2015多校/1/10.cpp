#include <bits/stdc++.h>//µü´ú
using namespace std;
typedef long long LL;
#define pb push_back
int p[19] = {0, -2, -3, -5, -7, -11, -13, -17, -19, -23, -29, -31, -37, -41, -43, -47, -53, -59, -61}; 
vector<int> a;
LL gao(LL x) {
	LL t = x;
	for (int i = 0; i < a.size(); ++i) {
		LL cnt = (LL)pow(x + 0.5, 1.0 / abs(a[i])) - 1;
		if (a[i] > 0)	t += cnt;
		else t -= cnt;
	}
	return t - 1;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int r;
		LL n;
		scanf("%I64d%d", &n, &r);
		a.clear();
		for (int i = 1; i <= 18 && abs(p[i]) <= r; ++i) {
			int k = a.size();
			for (int j = 0; j < k; ++j) {
				if (abs(p[i] * a[j]) > 63)	continue;
				a.pb(p[i] * a[j]);
			}
			a.pb(p[i]);
		}
		LL ans = n;
		while (1) {
			LL left = gao(ans);
			if (left == n)	break;
			ans += n - left;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
