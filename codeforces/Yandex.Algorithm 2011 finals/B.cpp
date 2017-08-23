#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 3e5;
vector<pii> p;
void gao(int l, int r) {
	int mid = l + r >> 1;
	for (int i = l; i <= r; ++i)	p.pb(mp(p[mid].F, p[i].S));
	if (l < mid)	gao(l, mid - 1);
	if (mid < r)	gao(mid + 1, r);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, x, y; i <= n; ++i) {
		scanf("%d%d", &x, &y);
		p.pb(mp(x, y));
	}
	sort(p.begin(), p.end());
	gao(0, n - 1);
	sort(p.begin(), p.end());
	n = unique(p.begin(), p.end()) - p.begin();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)	printf("%d %d\n", p[i].F, p[i].S);
	return 0;
}
