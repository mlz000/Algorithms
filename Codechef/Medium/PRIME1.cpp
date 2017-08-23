#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		memset(vis, 0, sizeof(vis));
		for (int i = 2; i * i <= r; ++i) {
			for (int j = max(i * 2, (l + i - 1) / i * i); j <= r; j += i) {
				if (!vis[j - l])	vis[j - l] = 1;
			}
		}
		for (int i = 0; i <= r - l; ++i)
			if (!vis[i] && i + l != 1)	printf("%d\n", i + l);
		puts("");
	}
	return 0;
}
