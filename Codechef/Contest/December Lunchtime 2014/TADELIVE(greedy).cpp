#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct data {
	int a, b, c;
}g[N];
bool cmp(const data &p, const data &q){
	return p.c > q.c;
}
int main() {
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	int sum = 0;
	for (int i = 1; i <= n; ++i)	scanf("%d", &g[i].a);
	for (int i = 1; i <= n; ++i)	scanf("%d", &g[i].b), g[i].c = g[i].a - g[i].b;
	sort(g + 1, g + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if ((g[i].c > 0 && x) || y == 0)	ans += g[i].a, --x;
		else ans += g[i].b, --y;
	}
	printf("%d\n", ans);
	return 0;
}
