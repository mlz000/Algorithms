#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = -2e9;
int a[N];
queue<int> q1, q2, q3;
int gao() {
	int x = q1.size() ? q1.front() : inf;
	int y = q2.size() ? q2.front() : inf;
	int z = q3.size() ? q3.front() : inf;
	if (x >= max(y, z))	{
		q1.pop();
		return x;
	}
	else if (y >= max(x, z)) {
		q2.pop();
		return y;
	}
	q3.pop();
	return z;
}
int main() {
	int n, m, q, u, v, t;
	scanf("%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; ++i)	q1.push(a[i]);
	for (int i = 1, now = 0; i <= m; ++i) {
		int len = gao() + now;
		if (i % t == 0)	printf("%d ", len);
		int x = (long long)u * len / v;
		int y = len - x;
		now += q;
		q2.push(x - now), q3.push(y - now);
	}
	puts("");
	for (int i = 1; i <= n + m; ++i) {
		int x = gao() + q * m;
		if (i % t == 0)	printf("%d ", x);
	}
	return 0;
}
