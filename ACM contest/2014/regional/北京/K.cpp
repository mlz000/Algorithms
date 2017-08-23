#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000005;
int a[N];
bool cnt[N];
int main() {
	int T, n;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		memset(cnt, 0, sizeof(cnt));
		printf("Case #%d: ", tt);
		scanf("%d", &n);
		int ans = 0, mn = 1;
		cnt[mn] = 1;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			if (a[i] == mn) {
				while (cnt[mn])	++mn;
				cnt[mn] = 1;
			}
			else cnt[a[i]] = 1, ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
