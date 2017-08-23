#include <bits/stdc++.h>
using namespace std;
#define ls rt << 1
#define rs rt << 1 | 1
const int N = 100005;
int sum[N << 2], tag[N << 2];
void down(int rt, int l, int r) {
	if (tag[rt]) {
		int mid = l + r >> 1;
		sum[ls] = mid - l + 1 - sum[ls];
		sum[rs] = r - mid - sum[rs];
		tag[ls] ^= 1;
		tag[rs] ^= 1;
		tag[rt] = 0;
	}
}
void change(int rt, int l, int r, int x, int y) {
	if (l >= x && r <= y) {
		sum[rt] = r - l + 1 - sum[rt];
		tag[rt] ^= 1;
		return ;
	}
	down(rt, l, r);
	int mid = l + r >> 1;
	if (x <= mid)	change(ls, l, mid, x, y);
	if (y > mid)	change(rs, mid + 1, r, x, y);
	sum[rt] = sum[ls] + sum[rs];
}
int query(int rt, int l, int r, int x, int y) {
	if (l >= x && r <= y)	return sum[rt];
	int mid = l + r >> 1;
	down(rt, l, r);
	int t = 0;
	if (x <= mid)	t += query(ls, l, mid, x, y);
	if (y > mid)	t += query(rs, mid + 1, r, x, y);
	return t;
}
int main() {
	int n, q, op, x, y;
	scanf("%d%d", &n, &q);
	while (q--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op)	printf("%d\n", query(1, 1, n, x + 1, y + 1));
		else change(1, 1, n, x + 1, y + 1);	
	}
	return 0;
}
