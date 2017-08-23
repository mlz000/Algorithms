#include <bits/stdc++.h>
using namespace std;
bool vis[1005];
char s[10];
int main() {
	int n, k, x, cnt = 0;
	scanf("%d%d", &n, &k);
	while (k--) {
		scanf("%s", s);
		if (s[4] == 'K') {
			scanf("%d", &x);
			if (!vis[x])	vis[x] = 1, ++cnt;
			else vis[x] = 0, --cnt;
		}
		else memset(vis, 0, sizeof(vis)), cnt = 0;
		printf("%d\n", cnt);
	}
	return 0;
}

