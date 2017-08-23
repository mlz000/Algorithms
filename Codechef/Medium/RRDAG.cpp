#include <bits/stdc++.h>//ππ‘Ï
using namespace std;
const int N = 2000;
int deg[N], v[N], ans[N][N];
char s[N][N];
int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)	scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == '1') {
				++deg[i + 1];
				++cnt;
			}
		}
	printf("%d\n", (n - 1) * n / 2 - cnt);
	priority_queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (!deg[i])	q.push(i);
	while (q.size()) {
		int x = q.top();
		v[x] = 1;
		q.pop();
		for (int i = 1; i <= n; ++i)
			if (!v[i] && s[i - 1][x - 1] == '0')	ans[i][x] = 1;
		for (int i = 1; i <= n; ++i)
			if (s[i - 1][x - 1] == '1')	
				if (!--deg[i])	q.push(i);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (ans[i][j])	printf("%d %d\n", i, j);
	return 0;
}
