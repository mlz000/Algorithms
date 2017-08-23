#include <bits/stdc++.h>
using namespace std;
#define ls (rt << 1)
#define rs (rt << 1 | 1)
const int N = 100005;
bool flag[N << 2];
int a[N];
long long sum[N << 2];
void build(int rt, int l, int r) {
	if (l == r) {
		sum[rt] = a[l];
		if (a[l] <= 1)	flag[rt] = 1;//不需要改
		return;
	}
	int mid = l + r >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	sum[rt] = sum[ls] + sum[rs];
	flag[rt] = flag[ls] & flag[rs];
}
long long query(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r)	return sum[rt];
	int mid = l + r >> 1;
	if (mid < L)	return query(rs, mid + 1, r, L, R);
	else if (mid >= R)	return query(ls, l, mid, L, R);
	else return query(ls, l, mid, L, mid) + query(rs, mid + 1, r, mid + 1, R); 
}
void change(int rt, int l, int r, int L, int R) {
	if (flag[rt])	return ;
	if (l == r) {
		sum[rt] = sqrt(sum[rt]);
		if (sum[rt] <= 1)	flag[rt] = 1;
		return;
	}	
	int mid = l + r >> 1;
	if (mid < L)	change(rs, mid + 1, r, L, R);
	else if (mid >= R)	change(ls, l, mid, L, R);
	else change(ls, l, mid, L, mid), change(rs, mid + 1, r, mid + 1, R);
	sum[rt] = sum[ls] + sum[rs];
	flag[rt] = flag[ls] & flag[rs];
}
int main() {
	int n, q;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	build(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r);
		if (l > r)	swap(l, r);
		if (x == 1)	printf("%lld\n", query(1, 1, n, l, r));
		else	change(1, 1, n, l, r);
	}
	return 0;
}
