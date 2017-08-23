#include <bits/stdc++.h>//cdq + dp
using namespace std;
typedef long long LL;
#define pb push_back
const int N = 50005;
struct data {
	int l, r, id;
}Q[N], a[N], b[N];
int tot, c[N << 1], dp[N];
vector<int> g;
bool cmp(const data &p, const data &q) {
	if (p.r != q.r)	return p.r < q.r;
	if (p.l != q.r)	return p.l > q.l;
	return p.id < q.id;
}
void add(int p, int x) {
	for (; p <= tot; p += p & -p)	c[p] = max(c[p], x);
}
void clr(int p) {
	for (; p <= tot; p += p & -p)	c[p] = 0;
}
int ask(int p) {
	int t = 0;
	for (; p; p -= p & -p)	t = max(t, c[p]);
	return t;
}
void cdq(int l, int r) {
	if (l == r) {
		dp[Q[l].id] = max(dp[Q[l].id], 1);
		return ;
	}
	int mid = l + r >> 1;
	cdq(mid + 1, r);
	int cnt1 = 0, cnt2 = 0;
	for (int i = l; i <= mid; ++i)	a[++cnt1] = Q[i];
	for (int i = mid + 1; i <= r; ++i)	b[++cnt2] = Q[i];
	sort(a + 1, a + cnt1 + 1, cmp), sort(b + 1, b + cnt2 + 1, cmp);
	int j = cnt2;
	for (int i = cnt1; i >= 1; --i) {
		for (; j >= 1 && b[j].r >= a[i].r; --j)
			add(b[j].l, dp[b[j].id]);
		dp[a[i].id] = max(dp[a[i].id], ask(a[i].l) + 1);
	}
	for (j = 1; j <= cnt2; ++j)	clr(b[j].l);
	cdq(l, mid);
}
int main() {
	int n;
	while (~scanf("%d", &n)) {
		memset(dp, 0, sizeof(dp));
		memset(c, 0, sizeof(c));
		g.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Q[i].l);
			Q[i].id = i;
			g.pb(Q[i].l);
		}
		sort(g.begin(), g.end());
		tot = unique(g.begin(), g.end()) - g.begin();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Q[i].r);
			Q[i].l = lower_bound(g.begin(), g.end(), Q[i].l) - g.begin() + 1;
		}
		cdq(1, n);
		int ans = 0, pre = -1;
		for (int i = 1; i <= n; ++i)	ans = max(ans, dp[i]);
		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i) {
			if (dp[i] == ans && (pre == -1 || Q[i].l <= Q[pre].l && Q[i].r >= Q[pre].r)) {
				if (~pre)	printf(" ");
				printf("%d", i);
				--ans;
				pre = i;
			}
		}
		puts("");
	}
	return 0;
}
