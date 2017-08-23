#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
char s[N];
int f[N][2];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		int l = strlen(s + 1);
		f[1][0] = f[1][1] = 0;
		for (int i = 1; i <= l; ++i) {
			if (i == 1) {
				if (s[i] == '+')	f[i][0] = 1;
				else f[i][1] = 1;
			}
			else {
				if (s[i] == '+')	f[i][1] = f[i - 1][0], f[i][0] = f[i - 1][1] + 1;
				else f[i][0] = f[i - 1][1], f[i][1] = f[i - 1][0] + 1;
			}
		}
		printf("%d\n", min(f[l][0], f[l][1]));
	}
	return 0;
}
