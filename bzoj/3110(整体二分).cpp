#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 50005;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
int n, m, ans[N], cnt[N];
struct data {
	int p, l, r, k, num, cur;
}q[N], q1[N], q2[N];
struct BIT {
	int c[N];
    void add(int p, int w) {
		for (; p <= n; p += p & -p)	c[p] += w;
	}
	int sum(int p) {
		int t = 0;
		for (; p; p -= p & -p)	t += c[p];
		return t;
	}
}a, b;
void solve(int l, int r, int x, int y) {
	if (x > y)	return;
	if (l == r)	{
		for (int i = x; i <= y; ++i) 
			if (q[i].p == 2)	ans[q[i].num] = l;
		return ;
	}
	int mid = l + r >> 1;
	for (int i = x; i <= y; ++i) {
		if (q[i].p == 1) {
			if (q[i].k > mid) {
				a.add(q[i].l, 1), a.add(q[i].r + 1, -1);//区间对答案贡献+1
				b.add(q[i].l, q[i].l), b.add(q[i].r + 1, -q[i].r - 1);
			}
		}
		else cnt[q[i].num] = ((q[i].r + 1) * a.sum(q[i].r) - b.sum(q[i].r)) - 
							 ((q[i].l * a.sum(q[i].l - 1)) - b.sum(q[i].l - 1));	
	}
	for (int i = x; i <= y; ++i) {
		if (q[i].p == 1 && q[i].k > mid) {
				a.add(q[i].l, -1), a.add(q[i].r + 1, 1);
				b.add(q[i].l, -q[i].l), b.add(q[i].r + 1, q[i].r + 1);		
		}
	}
	int t1 = 0, t2 = 0;
	for (int i = x; i <= y; ++i) {
		if (q[i].p == 1) {
			if (q[i].k <= mid)	q1[++t1] = q[i];
			else q2[++t2] = q[i];
		}
		else {
			if (q[i].cur + cnt[q[i].num] < q[i].k)	q[i].cur += cnt[q[i].num], q1[++t1] = q[i];
			else q2[++t2] = q[i];
		}
	}
	copy(q1 + 1, q1 + t1 + 1, &q[x]);
	copy(q2 + 1, q2 + t2 + 1, &q[x + t1]);
	solve(l, mid, x, x + t1 - 1);
	solve(mid + 1, r, x + t1, y);
}
int main() {
	read(n), read(m);
	int tot = 0;
	for (int i = 1; i <= m; ++i) {
		read(q[i].p), read(q[i].l), read(q[i].r), read(q[i].k);
		if (q[i].p == 2)	q[i].num = ++tot;	
	}
	solve(-n, n, 1, m); 
	for (int i = 1; i <= tot; ++i)	printf("%d\n", ans[i]);
	return 0;
}
