#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, a[N];
bool f;
void dfs(int p, int cnt, int now) {
	if (p == n + 1)	{
		if (!now && cnt)	f = 1;
		return ;
	}
	dfs(p + 1, cnt, now);
	dfs(p + 1, cnt + 1, now ^ a[p]);
}
int main() {
	for (int i = 1; i <= 10; ++i) {
		scanf("%d", &n);
		for (int j = 1; j <= n; ++j)	scanf("%d", &a[j]);
		f = 0;
		dfs(1, 0, 0);
		printf("%s\n", !f ? "YES" : "NO");
	}
	return 0;
}
