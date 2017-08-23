#include <bits/stdc++.h>
using namespace std;
const int N = 1005 * 1005;
struct data {
	int f, op, x1, y1, x2, y2;
}Q[N];
int g[N][4], f[N], sz[N], n, m;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
inline int code(int x, int y) {
	return (x - 1) * m + y;
}
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main() {
	int T, q;
	scanf("%d", &T);
	while (T--) {
		long long ans = 0;
		read(n), read(m), read(q);
		for (int i = 1; i <= q; ++i) {
			read(Q[i].op);
			if (Q[i].op == 1) {
				read(Q[i].x1), read(Q[i].y1);
				Q[i].x2 = Q[i].x1, Q[i].y2 = Q[i].y1 + 1;
				int t1 = code(Q[i].x1, Q[i].y1), t2 = code(Q[i].x2, Q[i].y2);
				if (g[t1][3] != 1)	Q[i].f = 1;
				g[t1][3] = g[t2][2] = 1;
			}
			else if (Q[i].op == 2) {
				read(Q[i].x1), read(Q[i].y1);
				Q[i].x2 = Q[i].x1 + 1, Q[i].y2 = Q[i].y1;
				int t1 = code(Q[i].x1, Q[i].y1), t2 = code(Q[i].x2, Q[i].y2);
				if (g[t1][1] != 1)	Q[i].f = 1;
				g[t1][1] = g[t2][0] = 1;
			}
			else if (Q[i].op == 3) read(Q[i].x1), read(Q[i].y1), read(Q[i].x2), read(Q[i].y2);
		}
		for (int i = 1; i <= n * m; ++i)	f[i] = i, sz[i] = 1;
		int mx = 1;
		for (int i = 1; i <= n * m; ++i) {
			if (!g[i][0] && i - m >= 1)	{
				int fx = find(i), fy = find(i - m);
				if (fx != fy)	f[fx] = fy, sz[fy] += sz[fx], mx = max(mx, sz[fy]);
			}
			if (!g[i][1] && i + m <= n * m)	 {
				int fx = find(i), fy = find(i + m);
				if (fx != fy)	f[fx] = fy, sz[fy] += sz[fx], mx = max(mx, sz[fy]);
			}
			if (!g[i][2] && i - 1 >= 1 && (i % m) != 1) {
				int fx = find(i), fy = find(i - 1);
				if (fx != fy)	f[fx] = fy, sz[fy] += sz[fx], mx = max(mx, sz[fy]);
			}
			if (!g[i][3] && i + 1 <= n * m && (i % m) != 0)	{
				int fx = find(i), fy = find(i + 1);
				if (fx != fy)	f[fx] = fy, sz[fy] += sz[fx], mx = max(mx, sz[fy]);
			}
		}
		for (int i = q; i >= 1; --i) {
			if ((Q[i].op == 1 || Q[i].op == 2) && Q[i].f == 1) {
				int t1 = code(Q[i].x1, Q[i].y1), t2 = code(Q[i].x2, Q[i].y2);
				int fx = find(t1), fy = find(t2);
				if (fx != fy)	f[fx] = fy, sz[fy] += sz[fx], mx = max(mx, sz[fy]);
			}
			else if (Q[i].op == 3) {
				int t1 = code(Q[i].x1, Q[i].y1), t2 = code(Q[i].x2, Q[i].y2);
				int fx = find(t1), fy = find(t2);
				ans += (fx == fy);				
			}
			else if (Q[i].op == 4)	ans += mx;
		}
		for (int i = 1; i <= q; ++i) {
			if (Q[i].op == 1 && Q[i].f == 1) {
				int t1 = code(Q[i].x1, Q[i].y1), t2 = code(Q[i].x2, Q[i].y2);
				g[t1][3] = g[t2][2] = 0;
			}	
			else if (Q[i].op == 2 && Q[i].f == 1) {
				int t1 = code(Q[i].x1, Q[i].y1), t2 = code(Q[i].x2, Q[i].y2);
				g[t1][1] = g[t2][0] = 0;
			}	
			Q[i].f = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
