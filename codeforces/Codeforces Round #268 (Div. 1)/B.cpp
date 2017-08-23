#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int p[N];
map <int, int> pos;
queue <int> q;
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; ++i)	scanf("%d", &p[i]), pos[p[i]] = 1;
	for (int i = 1; i <= n; ++i)	if (!pos[a - p[i]])	pos[p[i]] = 2, q.push(p[i]);
	int f = 1;
	while(q.size()) {
		int t = q.front();
		q.pop();
		if (!pos[b - t]) {
			f = 0;
			break;
		}
		if (pos[b - t] == 2)	continue;
		pos[b - t] = 2;
		pos[a - b + t] = 2;
		q.push(a - b + t);
	}
	if (!f)	puts("NO");
	else {
		puts("YES");
		for (int i = 1; i <= n; ++i)	cout << pos[p[i]] - 1 << ' ';
	}
	return 0;
}
