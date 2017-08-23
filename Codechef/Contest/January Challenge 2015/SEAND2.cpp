#include <bits/stdc++.h>
using namespace std;
const int N = 1005, inf = ~0u >> 1;
char s[N];
int a[N], b[N / 10], c[N];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		srand(time(0));
		scanf("%s%d", s, &n);
		int l = strlen(s);
		for (int i = 0; i < l; ++i)	a[i] = s[i] - '0';
		memcpy(c, a, sizeof(a));
		int ans = inf; 
		for (int i = 0; i < n; ++i)	scanf("%d", &b[i]);
		for (int i = 1; i <= 120; ++i) {
			int now = 0;
			random_shuffle(a, a + l);
			for (int j = 0; j < n; ++j) {
				int t = 0;
				for (int k = 0; k < l; ++k)	t = (t * 10 + a[k]) % b[j];
				now += t;
				if (now > ans)	break;
			}
			if (now < ans) {
				ans = now;
				memcpy(c, a, sizeof(a));
			}
			else memcpy(a, c, sizeof(c));
		}
		for (int i = 0; i < l; ++i)	printf("%d", c[i]);
		puts("");
	}
	return 0;
}


