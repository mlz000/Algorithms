#include <bits/stdc++.h>//good
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int N = 100010;
typedef long long LL;
int n;
char s[10];
struct Node {
	int l, r, h0, h1, s0, s1, x0, x1;
}a[N << 2];
int g[2][N][4];//U D L R
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
Node merge(Node a, Node b) {
	Node c;
	int f0 = g[0][a.r][3], f1 = g[1][a.r][3];
	c.h0 = (a.h0 && f0 && b.h0) | (a.x0 && f1 && b.x1);
	c.h1 = (a.h1 && f1 && b.h1) | (a.x1 && f0 && b.x0);
	c.s0 = a.s0 | (a.h0 && f0 && b.s0 && f1 && a.h1);
	c.s1 = b.s1 | (b.h0 && f0 && a.s1 && f1 && b.h1);
	c.x0 = (a.h0 && f0 && b.x0) | (a.x0 && f1 && b.h1);
	c.x1 = (a.h1 && f1 && b.x1) | (a.x1 && f0 && b.h0);
	c.l = a.l, c.r = b.r;
	return c;
}
void modify(int x1, int y1, int x2, int y2, int x) {
	if (x1 == x2)	g[x1][y1][3] = g[x1][y2][2] = x;
	else g[0][y1][1] = g[1][y1][0] = x;
}
void build(int rt, int l, int r) {
	a[rt].l = l, a[rt].r = r;
	if (l == r) {
		a[rt].h0 = a[rt].h1 = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
}
void change(int rt, int l, int r, int x1, int y1, int x2, int y2) {
	int mid = l + r >> 1;
	if (x1 == x2 && mid == y1) {
		a[rt] = merge(a[ls], a[rs]);
		return;
	}
	if (l == r && y1 == y2) {
		a[rt].s0 = a[rt].s1 = a[rt].x0 = a[rt].x1 = g[0][y1][1];
		if (a[rt].s0)	a[rt].x0 = a[rt].x1 = 1;
		return ;
	}
	if (y1 <= mid)	change(ls, l, mid, x1, y1, x2, y2);
	else change(rs, mid + 1, r, x1, y1, x2, y2);
	a[rt] = merge(a[ls], a[rs]);
}
Node find(int rt, int l, int r) {
	if (l <= a[rt].l && a[rt].r <= r)	return a[rt];
	int mid = a[rt].l + a[rt].r >> 1;
	if (r <= mid)	return find(ls, l, r);
	if (l > mid)	return find(rs, l, r);
	else return merge(find(ls, l, r), find(rs, l, r));
}
bool ask(int x1, int y1, int x2, int y2) {
	Node a = find(1, 1, y1), b = find(1, y1, y2), c = find(1, y2, n);
	b.s0 |= a.s1, b.s1 |= c.s0;
	if (x1 == x2) {
		if (x1 == 0)	return b.h0 | (b.s0 && b.h1 && b.s1) | (b.s0 && b.x1) | (b.x0 && b.s1);
		else return b.h1 | (b.s0 && b.h0 && b.s1) | (b.s0 && b.x0) | (b.x1 && b.s1);
	}
	else {
		if (x1 < x2)	return b.x0 | (b.h0 && b.s1) | (b.s0 && b.h1);
		else return b.x1 | (b.h1 && b.s1) | (b.s0 && b.h0);
	}	
}
int main(){
	read(n);
	build(1, 1, n);
	while (scanf("%s", s) && s[0] != 'E') {
		int x1, y1, x2, y2;
		read(x1), read(y1), read(x2), read(y2);
		--x1, --x2;
		if (s[0] == 'C') {
			if (y1 > y2)	swap(y1, y2);
			modify(x1, y1, x2, y2, 0);
			change(1, 1, n, x1, y1, x2, y2);
		}
		else if (s[0] == 'O') {
			if (y1 > y2)	swap(y1, y2);
			modify(x1, y1, x2, y2, 1);
			change(1, 1, n, x1, y1, x2, y2);
		}
		else {
			if (y1 > y2)	swap(x1, x2), swap(y1, y2);
			if (ask(x1, y1, x2, y2))	puts("Y");
			else puts("N");
		}
	}
	return 0;
}
