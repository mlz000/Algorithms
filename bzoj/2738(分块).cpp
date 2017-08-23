#include <bits/stdc++.h>//·Ö¿é
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 505, M = 60005;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
bool v[N][N], f[M];
int s[N][N], ans[M];
struct data {
	int x1, y1, x2, y2, k;
}Q[M];
struct node {
	int x, y, num;
	node(){}
	node(int x, int y, int num) : x(x), y(y), num(num){}
}a[N * N];
bool cmp(const node &p, const node &q) {
	return p.num < q.num;
}
int main() {
	int n, q, cnt = 0;
	read(n), read(q);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1, x; j <= n; ++j) {
			read(x);
			a[++cnt] = node(i, j, x);
		}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= q; ++i) {
		read(Q[i].x1), read(Q[i].y1), read(Q[i].x2), read(Q[i].y2), read(Q[i].k);
	}
	int sz = 1.3 + n * n / sqrt(q);
	for (int l = 1; l <= cnt; l += sz) {
		int r = min(cnt, l + sz - 1);
		for (int i = l; i <= r; ++i)	v[a[i].x][a[i].y] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v[i][j];
		for (int i = 1; i <= q; ++i) {
			if (!f[i]) {
				int sum = s[Q[i].x2][Q[i].y2] - s[Q[i].x2][Q[i].y1 - 1] - s[Q[i].x1 - 1][Q[i].y2] + s[Q[i].x1 - 1][Q[i].y1 - 1];
				if (sum >= Q[i].k) {
					f[i] = 1;
					int t = sum - Q[i].k;
					for (int j = r; j >= l; --j) {
						if (a[j].x >= Q[i].x1 && a[j].x <= Q[i].x2 && a[j].y >= Q[i].y1 && a[j].y <= Q[i].y2)	if (!t) {
							ans[i] = a[j].num;
							break;
						}
						else --t;
					}
				}
			}
		}
	}
	for (int i = 1; i <= q; ++i)	printf("%d\n", ans[i]);
	return 0;
}
