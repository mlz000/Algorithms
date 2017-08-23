#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		multiset<int> S;
		for (int i = 1, x; i <= n; ++i) {
			scanf("%d", &x);
			S.insert(x);
		}
		LL ans = 0;
		for (int i = 1; i < n; ++i) {
			int t = 0;
			t += *S.begin();
			S.erase(S.begin());
			t += *S.begin();
			S.erase(S.begin());
			ans += t;
			S.insert(t);
		}
		cout << ans << endl;
	}

	return 0;
}
