#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char s[N];
int du[30], can[30], f[30];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		memset(du, 0, sizeof(du));
		memset(can, 0, sizeof(can));
		scanf("%d", &n);
		for (int i = 0; i < 26; ++i)	f[i] = i;
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s);
			int l = strlen(s);
			int a = s[0] - 'a', b = s[l - 1] - 'a';
			++du[a];
			--du[b];
			for (int j = 0; j < 26; ++j)
				if (f[j] == f[b])	f[j] = f[a];
			can[a] = can[b] = 1;
		}
		int f1 = 0, f2 = 0, ok = 1, x = -1;
		for (int i = 0; i < 26; ++i) 
			if (can[i]) {
				if (du[i] == 0) {
					if (x != f[i]) {
						if (x == -1)	x = f[i];
						else ok = 0;
					}
				}
				else if (du[i] == -1) {
					if (f1)	ok = 0;
					else f1 = 1;
				}
				else if (du[i] == 1) {
					if (f2)	ok = 0;
					else f2 = 1;
				}
				else ok = 0;
			}
		printf("%s\n", ok ? "Ordering is possible." : "The door cannot be opened.");
	}
	return 0;
}
