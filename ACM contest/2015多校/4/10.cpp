#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int N = 105;
struct data {
	int x, y, dir;
	data() {}
	data(int x, int y, int dir): x(x), y(y), dir(dir) {}
};
struct Drop{
	int x, y, z;
	Drop() {}
	Drop(int x, int y, int z): x(x), y(y), z(z) {}
};
Drop a[N];
int f[N][N], ans[N];
int r, c, n, T;
queue<data> q[2];
void work() {
	int cnt = 0, cur = 1;
	for (int clock = 1; clock <= T; ++clock, cur ^= 1) {
		if (cnt == n || q[cur ^ 1].empty()) break;
		while (q[cur ^ 1].size()) {
			data t = q[cur ^ 1].front();
			q[cur ^ 1].pop();
			t.x += dx[t.dir];
			t.y += dy[t.dir];
			if (t.x < 0 || t.x > r || t.y < 0 || t.y > c)	continue;
			int k = f[t.x][t.y];
			if (k != 0)	++a[k].z;
			else	q[cur].push(data(t.x, t.y, t.dir));
		}
		for (int i = 1; i <= n; ++i) {
			if (a[i].z > 4) {
				++cnt;
				a[i].z = 0;
				for (int j = 0; j < 4; ++j)	q[cur].push(data(a[i].x, a[i].y, j));
				f[a[i].x][a[i].y] = 0;
				ans[i] = clock;
			}
		}
	}
}
int main() {
	while (scanf("%d%d%d%d", &r, &c, &n, &T) != EOF) {
		memset(f, 0, sizeof f);
		for (int i = 1, x, y, z; i <= n; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			f[x][y] = i;
			a[i] = Drop(x, y, z);
		}
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 0; i < 2; ++i)	
			while (q[i].size()) q[i].pop();
		for (int i = 0; i < 4; ++i)	q[0].push(data(x, y, i));//dir
		work();
		for (int i = 1; i <= n; ++i) {
			if (a[i].z == 0)	printf("0 %d\n", ans[i]);
			else	printf("1 %d\n", a[i].z);
		}
	}
	return 0;
}

