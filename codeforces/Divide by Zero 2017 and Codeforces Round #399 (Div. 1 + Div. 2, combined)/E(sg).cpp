#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define S second
typedef long long LL;
const int N = 65;
map<pair<LL, int>, int> sg;
int a[N];
bool vis[N];
int gao(int x, LL mask) {
	if (!x)	return 0;
	auto it = sg.find(mp(x, mask));
	if (it != sg.end())	return it -> S;
	for (int i = 1; i <= x; ++i) {
		if (mask >> i & 1)	continue;
		gao(x - i, mask | (1 << i));
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= x; ++i) {
		if (mask >> i & 1)	continue;
		vis[gao(x - i, mask | (1 << i))] = 1;
	}
	int now = 0;
	for (int i = 0; i < N; ++i)
		if (!vis[i]) {
			now = i;
			break;
		}
	return sg[mp(x, mask)] = now;
}
int main() {
	for (int i = 1; i <= 60; ++i)
		a[i] = gao(i, 0);
	int n, now = 0;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		now ^= a[x];
	}
	if (!now)	puts("YES");
	else puts("NO");
	return 0;
}

