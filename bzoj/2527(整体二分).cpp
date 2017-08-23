#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 300005;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
vector<int> a[N];
int n, m, k, now, p[N], id[N], ans[N], q1[N], q2[N];
struct data {
	int l, r, num;
}q[N];
struct BIT {
    LL c[N];
	void add(int x, int w) {
		if (x > m)	return ;
		for (; x <= m; x += x & - x)	c[x] += w;
	}
    LL sum(int x) {
        LL t = 0;
        for (; x; x -= x & -x)	t += c[x];
		return t;
    }
    void gao(int x, int w) {
		if (q[x].l <= q[x].r) {
			add(q[x].l, w * q[x].num), add(q[x].r + 1, -w * q[x].num);
		}
		else {
			add(1, w * q[x].num), add(q[x].r + 1, -w * q[x].num), add(q[x].l, w * q[x].num);
		}
	}
}b;
void solve(int l, int r, int x, int y) {
    if (x > y)   return;
    if (l == r) {
        for (int i = x; i <= y; ++i) ans[id[i]] = l;
        return ;
    }
	int mid = l + r >> 1;
	int t1 = 0, t2 = 0;
	while (now + 1 <= mid) {
		++now;
		b.gao(now, 1);
	}
	while (now > mid) {
		b.gao(now, -1);
		--now;
	}
	for (int i = x; i <= y; ++i) {
		int t = id[i];
		LL sum = 0;
		for (int j = 0; j < a[t].size(); ++j) {
			int pos = a[t][j];
			sum += b.sum(pos);
			if (sum >= p[t])	break;
		}
		if (sum >= p[t])	q1[++t1] = id[i];
		else q2[++t2] = id[i];
	}
    copy(q1 + 1, q1 + t1 + 1, &id[x]);
    copy(q2 + 1, q2 + t2 + 1, &id[x + t1]);
    solve(l, mid, x, x + t1 - 1);
    solve(mid + 1, r, x + t1, y);
}
int main() {
    read(n), read(m);
    for (int i = 1, x; i <= m; ++i) {
    	read(x);
		a[x].pb(i);
	}
    for (int i = 1; i <= n; ++i)	read(p[i]);
	read(k);
	for (int i = 1; i <= k; ++i) {
		read(q[i].l), read(q[i].r), read(q[i].num);
	}
	q[++k].l = 1, q[k].r = m, q[k].num = (int)1e7;
	for (int i = 1; i <= n; ++i)	id[i] = i;
	solve(1, k, 1, n); 
    for (int i = 1; i <= n; ++i) {
		if (ans[i] != k)	printf("%d\n", ans[i]);
		else puts("NIE");
	}
    return 0;
}
