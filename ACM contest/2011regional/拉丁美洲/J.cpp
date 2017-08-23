#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ls (rt << 1)
#define rs (rt << 1 | 1)
typedef long long LL;
const int N = 100005;
LL b, P, po[N], tree[N << 2];
int L, n;
void modify(int rt, int l, int r, int p, int x) {
	if (l == r) {
		tree[rt] = x;
		return;
	}
	int mid = l + r >> 1;
	if (p <= mid)	modify(ls, l, mid, p, x);
	else modify(rs, mid + 1, r, p, x);
	tree[rt] = (tree[rs] + tree[ls] * po[r - mid]) % P;
}
LL ask(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) {
		return tree[rt] * po[R - r];
	}
	int mid = l + r >> 1;
	long long t = 0ll;
	if (L <= mid)	(t += ask(ls, l, mid, L, R)) %= P;
	if (R > mid)	(t += ask(rs, mid + 1, r, L, R)) %= P;
	return t;
}
int main() {
	while (scanf("%lld%lld%d%d", &b, &P, &L, &n) && b) {
		memset(tree, 0, sizeof(tree));
		po[0] = 1;
		for (int i = 1; i <= L; ++i)	po[i] = (po[i - 1] * b) % P;
		char s[5];
		while (n--) {
			scanf("%s", s);
			if (s[0] == 'E') {
				int x;
				LL y;
				scanf("%d%lld", &x, &y);
				modify(1, 1, L, x, y);
			}
			else {
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%lld\n", ask(1, 1, L, x, y));
			}
		}
		puts("-");
	}
	return 0;
}
