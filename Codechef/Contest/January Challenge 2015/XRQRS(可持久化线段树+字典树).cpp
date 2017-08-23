#include <bits/stdc++.h>
using namespace std;
const int N = 500005, M = N * 20;
int n;
struct Trie {
	int tot, ch[M][2], root[N], d[M];
	void insert(int x, int &y, int k, int w) {
		d[y = ++tot] = d[x] + 1;
		if (k < 0)	return;
		int t = (w >> k & 1);
		ch[y][t ^ 1] = ch[x][t ^ 1];
		insert(ch[x][t], ch[y][t], k - 1, w);
	}
	int query(int l, int r, int k, int w) {
		int ans = 0;
		if (k < 0)	return 0;
		int t = (w >> k & 1);
		if (d[ch[r][t ^ 1]] - d[ch[l][t ^ 1]])	return (1 << k) + query(ch[l][t ^ 1], ch[r][t ^ 1], k - 1, w);
		else query(ch[l][t], ch[r][t], k - 1, w);
	}
}trie;
struct Seg {
	int tot, root[N], d[M], l[M], r[M];
	void insert(int x, int &y, int L, int R, int w) {
		d[y = ++tot] = d[x] + 1;
		if (L == R)	return ;
		int mid = L + R >> 1;
		if (w <= mid)	r[y] = r[x], insert(l[x], l[y], L, mid, w);
		else l[y] = l[x], insert(r[x], r[y], mid + 1, R, w);
	}
	int query1(int x, int y, int L, int R, int w) {
		int t = 0;
		if (L == R)	return d[y] - d[x];
		int mid = L + R >> 1;
		if (w <= mid)	return query1(l[x], l[y], L, mid, w);
		else return d[l[y]] - d[l[x]] + query1(r[x], r[y], mid + 1, R, w);
	}
	int query2(int x, int y, int L, int R, int w) {
		if (L == R)	return L;
		int mid = L + R >> 1;
		if (w <= d[l[y]] - d[l[x]])	return query2(l[x], l[y], L, mid, w);
		else return query2(r[x], r[y], mid + 1, R, w - d[l[y]] + d[l[x]]);
	}
}seg;
int main() {
	int q, op, l, r, x;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &op);
		if (!op) {
			++n;
			scanf("%d", &x);
			seg.insert(seg.root[n - 1], seg.root[n], 1, 500000, x);
			trie.insert(trie.root[n - 1], trie.root[n], 20, x);
		}
		else if (op == 1) {
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", x ^ trie.query(trie.root[l - 1], trie.root[r], 20, x));
		}s
		else if (op == 2) {
			scanf("%d", &x);
			n -= x;
		}
		else if (op == 3) {
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", seg.query1(seg.root[l - 1], seg.root[r], 1, 500000, x));
		}
		else {
			scanf("%d%d%d", &l, &r, &x);
			printf("%d\n", seg.query2(seg.root[l - 1], seg.root[r], 1, 500000, x));
		}
	}
	return 0;
}
