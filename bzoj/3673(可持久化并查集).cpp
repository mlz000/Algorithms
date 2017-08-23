#include <bits/stdc++.h>//rope
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int N = 20005;
int f[N];
rope<int> *fa[N];
int find(int i, int x) {
	if (fa[i] -> at(x) != x) {
		int t = find(i, fa[i] -> at(x));
		if (t == fa[i] -> at(x))	return t;
		fa[i] -> replace(x, t);
		return t;
	}
	return x;
}
void Union(int i, int x, int y) {
	int fx = find(i, x), fy = find(i, y);
	fa[i] -> replace(fx, fy);
}
int main() {
	int n, m, op, x, y;
	int last = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)	f[i] = i;
	fa[0] = new rope<int> (f, f + n + 1);
	for (int i = 1; i <= m; ++i) {
		fa[i] = new rope<int> (*fa[i - 1]);
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &x, &y);
			Union(i, x ^ last, y ^ last);
		}
		else if (op == 2)	scanf("%d", &x), fa[i] = fa[x ^ last];
		else {
			scanf("%d%d", &x, &y);
			printf("%d\n", last = find(i, x) == find(i, y));
		}
		last = 0;
	}
	return 0;
}
