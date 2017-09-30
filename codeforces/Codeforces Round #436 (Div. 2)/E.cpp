#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 105;
struct data {
	int t, d, p, id;
}a[N];
bool cmp(const data& p, const data &q) {
	return p.d < q.d;
}
int n, f[2005], ans[2005];
vector<int> res[2005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d%d%d", &a[i].t, &a[i].d, &a[i].p), a[i].id = i;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) 
		for (int j = a[i].d - 1; j >= a[i].t; --j) {
			if (f[j] < f[j - a[i].t] + a[i].p) {
				f[j] = f[j - a[i].t] + a[i].p;
				res[j] = res[j - a[i].t];
				res[j].pb(a[i].id);
			}
		}
	int mx = 0, p;
	for (int i = 0; i <= 2000; ++i) 
		if (mx < f[i]) {
			mx = f[i];
			p = i;
		}
	printf("%d\n%d\n", mx, res[p].size());
	for (auto& x : res[p])	printf("%d ", x);
	return 0;
}
