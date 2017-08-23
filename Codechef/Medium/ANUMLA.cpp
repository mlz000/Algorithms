#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> g;
int a[16];
multiset<long long> s;
multiset<long long> :: iterator it;
int main() {
	int T, n, m;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		m = 1 << n;
		g.clear(), s.clear();
		for (int i = 0, x; i < m; ++i)	scanf("%d", &x), s.insert(x);
		g.pb(0), s.erase(0);
		for (int i = 0; i < n; ++i) {
			a[i] = *s.begin();
			int sz = g.size();
			for (int j = 0; j < sz; ++j) {
				it = s.find(g[j] + a[i]);
				g.pb(*it);
				s.erase(it);
			}
		}
		sort(a, a + n);
		for (int i = 0; i < n; ++i)	printf("%d ", a[i]);
		puts("");
	}
	return 0;
}
