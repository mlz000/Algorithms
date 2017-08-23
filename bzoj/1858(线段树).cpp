#include <bits/stdc++.h>//บรฬโ
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005;
struct Node {
	int lc[2], rc[2], mx[2], cnt[2], len; 
}p[N << 2];
int a[N], flag[N << 2];
void pushup(int rt) {
	p[rt].cnt[0] = p[ls].cnt[0] + p[rs].cnt[0];
	p[rt].cnt[1] = p[ls].cnt[1] + p[rs].cnt[1];
	p[rt].lc[0] = p[ls].lc[0] + (p[ls].lc[0] == p[ls].len ? p[rs].lc[0] : 0);
	p[rt].lc[1] = p[ls].lc[1] + (p[ls].lc[1] == p[ls].len ? p[rs].lc[1] : 0);
	p[rt].rc[0] = p[rs].rc[0] + (p[rs].rc[0] == p[rs].len ? p[ls].rc[0] : 0);
	p[rt].rc[1] = p[rs].rc[1] + (p[rs].rc[1] == p[rs].len ? p[ls].rc[1] : 0);
	p[rt].mx[0] = max(p[ls].mx[0], max(p[rs].mx[0], p[ls].rc[0] + p[rs].lc[0]));
	p[rt].mx[1] = max(p[ls].mx[1], max(p[rs].mx[1], p[ls].rc[1] + p[rs].lc[1]));
}
void build(int rt, int l, int r) {
	flag[rt] = -1;
	p[rt].len = r - l + 1;
	if (l == r) {
		p[rt].lc[a[l]] = p[rt].rc[a[l]] = p[rt].mx[a[l]] = p[rt].cnt[a[l]] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(rt);
}
void pushdown(int rt, int l, int r) {
	if (~flag[rt]) {
		int x = flag[rt];
		if (x == 2)	{
			swap(p[ls].lc[0], p[ls].lc[1]), swap(p[rs].lc[0], p[rs].lc[1]);
			swap(p[ls].rc[0], p[ls].rc[1]), swap(p[rs].rc[0], p[rs].rc[1]);
			swap(p[ls].cnt[0], p[ls].cnt[1]), swap(p[rs].cnt[0], p[rs].cnt[1]);
			swap(p[ls].mx[0], p[ls].mx[1]), swap(p[rs].mx[0], p[rs].mx[1]);
			flag[ls] = 1 - flag[ls], flag[rs] = 1 - flag[rs];
		}
		else {
			p[ls].lc[x] = p[ls].rc[x] = p[ls].cnt[x] = p[ls].mx[x] = p[ls].len;
			p[ls].lc[1 - x] = p[ls].rc[1 - x] = p[ls].cnt[1 - x] = p[ls].mx[1 - x] = 0;
			p[rs].lc[x] = p[rs].rc[x] = p[rs].cnt[x] = p[rs].mx[x] = p[rs].len;
			p[rs].lc[1 - x] = p[rs].rc[1 - x] = p[rs].cnt[1 - x] = p[rs].mx[1 - x] = 0;
			flag[ls] = flag[rs] = flag[rt];
		}
		flag[rt] = -1;
	}
}
void change(int rt, int l, int r, int L, int R, int x) {
	if (L <= l && R >= r) {
		p[rt].lc[x] = p[rt].rc[x] = p[rt].cnt[x] = p[rt].mx[x] = p[rt].len;
		p[rt].lc[1 - x] = p[rt].rc[1 - x] = p[rt].cnt[1 - x] = p[rt].mx[1 - x] = 0;
		flag[rt] = x;
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if (mid < L)	change(rs, mid + 1, r, L, R, x);
	else if (mid >= R)	change(ls, l, mid, L, R, x);
	else {
		change(ls, l, mid, L, mid, x);
		change(rs, mid + 1, r, mid + 1, R, x);
	}
	pushup(rt);
}
void reverse(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) {
		swap(p[rt].lc[0], p[rt].lc[1]), swap(p[rt].rc[0], p[rt].rc[1]);
		swap(p[rt].cnt[0], p[rt].cnt[1]), swap(p[rt].mx[0], p[rt].mx[1]);
		flag[rt] = 1 - flag[rt];
		return;
	}
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if (mid < L)	reverse(rs, mid + 1, r, L, R);
	else if (mid >= R)	reverse(ls, l, mid, L, R);
	else {
		reverse(ls, l, mid, L, mid);
		reverse(rs, mid + 1, r, mid + 1, R);
	}
	pushup(rt);	
}
int ask(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r)	return p[rt].cnt[1];
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if (mid < L)	return ask(rs, mid + 1, r, L, R);
	else if (mid >= R)	return ask(ls, l, mid, L, R);
	else return ask(ls, l, mid, L, mid) + ask(rs, mid + 1, r, mid + 1, R);
}
Node ask2(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r)	return p[rt];
	pushdown(rt, l, r);
	int mid = l + r >> 1;
	if (mid < L)	return ask2(rs, mid + 1, r, L, R);
	else if (mid >= R)	return ask2(ls, l, mid, L, R);
	else {
		Node t1 = ask2(ls, l, mid, L, mid), t2 = ask2(rs, mid + 1, r, mid + 1, R);	
		Node t3;
		t3.lc[1] = t1.lc[1] + (t1.lc[1] == t1.len ? t2.lc[1] : 0);
		t3.rc[1] = t2.rc[1] + (t2.rc[1] == t2.len ? t1.rc[1] : 0);
		t3.len = t1.len + t2.len;
		t3.mx[1] = max(t1.mx[1], max(t2.mx[1], t1.rc[1] + t2.lc[1])); 
		return t3;
	}
}
int main() {
	int n, q;
	scanf("%d%d",&n, &q);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	build(1, 1, n);
	while (q--) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r);
		++l, ++r;
		switch(x) {
			case 0: change(1, 1, n, l, r, 0);break;
			case 1: change(1, 1, n, l, r, 1);break;
			case 2: reverse(1, 1, n, l, r);break;
			case 3: printf("%d\n", ask(1, 1, n, l, r));break;
			case 4: {
				Node t = ask2(1, 1, n, l, r);
				printf("%d\n", t.mx[1]);
			}
		}
	}
	return 0;
}
