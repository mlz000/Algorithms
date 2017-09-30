#include <bits/stdc++.h>
using namespace std;
const int N = 105;
map<int, int> cnt;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		++cnt[x];
	}
	if (cnt.size() != 2 || cnt.begin() -> second != cnt.rbegin() -> second)	puts("NO");
	else puts("YES"), printf("%d %d\n", cnt.begin() -> first, cnt.rbegin() -> first);
	return 0;
}
