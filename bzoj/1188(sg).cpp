#include <bits/stdc++.h>
using namespace std;
const int N = 25, M = 10005;
int n, p[N], sg[N];
bool mark[M];
int gao(int x) {
	if (x == n)	return 0;
	if (~sg[x])	return sg[x];
	memset(mark, 0, sizeof(mark));
	for (int i = x + 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) {
			mark[gao(i) ^ gao(j)] = 1;
		}
	for (int i = 0; i < M; ++i)
		if (!mark[i])	return sg[x] = i;	
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(sg, -1, sizeof(sg));
		for (int i = 1; i <= n; ++i)	scanf("%d", &p[i]);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (p[i] & 1)	ans ^= gao(i);
		int f = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				for (int k = j; k <= n; ++k) {
					if (!(ans ^ gao(i) ^ gao(j) ^ gao(k))) {
						++f;
						if (f == 1)	printf("%d %d %d\n", i - 1, j - 1, k - 1);
					}
				}
		if (f)	printf("%d\n", f);
		if (!f)	puts("-1 -1 -1"), puts("0");
	}
	return 0;
}

