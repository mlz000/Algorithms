#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 1e5 + 5;
int a[N], pos[N], ans[N], mx[N << 2];
bool vis[N];
void up(int rt) {
	mx[rt] = max(mx[ls], mx[rs]);
}
void build(int rt, int l, int r) {
	if (l == r) {
		mx[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	up(rt);
}
int ask(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return mx[rt];
	}
	int t = 0;
	int mid = l + r >> 1;
	if (L <= mid)	t = max(t, ask(ls, l, mid, L, R));
	if (R > mid)	t = max(t, ask(rs, mid + 1, r, L, R));
	return t;
}
void change(int rt, int l, int r, int p, int x) {
	if (l == r) {
		mx[rt] = x;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	change(ls, l, mid, p, x);
	else change(rs, mid + 1, r, p, x);
	up(rt);
}
int main() {
	int n, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			vis[a[i]] = 0;
			pos[a[i]] = i;
		}
		build(1, 1, n);
		set<int> S;
		for (int i = 1; i <= n; ++i) {
			if (vis[i])	continue;
			int l = 1;
			if (S.size()) {
				set<int> :: iterator it = S.lower_bound(pos[i]);;
				if (it != S.begin()) l = *(--it) + 1;
			}
			int t =	ask(1, 1, n, l, pos[i]);
			if (pos[i] < n && a[pos[i] + 1] > t && !vis[a[pos[i] + 1]]) {
				ans[i] = a[pos[i] + 1];
				change(1, 1, n, pos[i] + 1, 0);
			}
			else {
				ans[i] = t;
				vis[t] = 1;
				for (int j = pos[t]; j < pos[i]; ++j) {
					ans[a[j]] = a[j + 1];
					vis[a[j + 1]] = 1;
				}
				S.insert(pos[i]);
			}
		}
		for (int i = 1; i < n; ++i)	printf("%d ", ans[i]);
		printf("%d\n", ans[n]);
	}
	return 0;
}
