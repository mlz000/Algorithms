#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], l1, l2;
char s1[N], s2[N];
bool v[N];
bool check(int t) {
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= t; ++i)	v[a[i]] = 1;
	bool ok = 0;
	int i = 1, j = 1;
	while (i <= l1 && j <= l2) {
		if  (v[i]) {
			++i;
			continue;
		}
		if (s1[i] == s2[j])	++i, ++j;
		else ++i;
	}
	return j > l2;
}
int main() {
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
	for (int i = 1; i <= l1; ++i)	scanf("%d", &a[i]);
	int l = 1, r = l1, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid))	ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
