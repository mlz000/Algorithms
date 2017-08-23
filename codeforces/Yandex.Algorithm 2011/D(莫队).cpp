#include <bits/stdc++.h>//Äª¶Ó
using namespace std;
const int N = 200005;
int L, R, sz, a[N];
long long ans[N], cnt[N * 5], tot;
struct Query {
	int l, r, id;
}q[N];
bool cmp(const Query &p, const Query &q) {
	return p.l / sz < q.l / sz || (p.l / sz == q.l / sz && p.r < q.r);	
}
long long ask(int x, int y, int f) {
	if (!f) {
		for (int i = x; i <= y; ++i) {
			tot += ((cnt[a[i]] << 1ll) + 1) * a[i];
			++cnt[a[i]];
		}
	}
	else {
		for (int i = x; i < L; ++i) {
			tot += ((cnt[a[i]] << 1ll) + 1) * a[i];
			++cnt[a[i]];		
		}
		for (int i = L; i < x; ++i) {
			tot -= ((cnt[a[i]] << 1ll) - 1) * a[i];
			--cnt[a[i]];
		}
		for (int i = R + 1; i <= y; ++i) {
			tot += ((cnt[a[i]] << 1ll) + 1) * a[i];
			++cnt[a[i]];		
		}
		for (int i = y + 1; i <= R; ++i) {
			tot -= ((cnt[a[i]] << 1ll) - 1) * a[i];
			--cnt[a[i]];			
		}
	}
	L = x, R = y;
	return tot;
}
int main() {
	int n, t;
	scanf("%d%d", &n, &t);
	sz = sqrt(n);
	for (int i = 0; i < n; ++i)	scanf("%d", &a[i]);
	for (int i = 0; i < t; ++i) {
		scanf("%d%d", &q[i].l, &q[i].r);
		--q[i].l, --q[i].r;
		q[i].id = i;
	}
	sort(q, q + t, cmp);
	for (int i = 0; i < t; ++i)	ans[q[i].id] = ask(q[i].l, q[i].r, i);
	for (int i = 0; i < t; ++i)	printf("%I64d\n", ans[i]);
	return 0;
}
