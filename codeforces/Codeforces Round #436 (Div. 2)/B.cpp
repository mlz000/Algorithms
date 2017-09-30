#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int cnt[26];
char s[N];
int main() {
	int n, ans = 0;
	scanf("%d", &n);
	scanf("%s", s);
	s[n++] = 'A';
	for (int i = 0; i < n; ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			int t = 0;
			for (int j = 0; j < 26; ++j)	t += cnt[j] > 0;
			ans = max(ans, t);
			memset(cnt, 0, sizeof(cnt));
			continue;
		}
		++cnt[s[i] - 'a'];
	}
	printf("%d\n", ans);
	return 0;
}
