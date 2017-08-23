#include <bits/stdc++.h>//construction
using namespace std;
#define pb push_back
typedef long long LL;
const int N = 30;
int a[N][N];
int main() {
	int T;
	LL k;
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof(a));
		puts("28 21");
		for (int i = 1; i <= 8; ++i)
			for (int j = 1; j <= 8; ++j)
				a[i][j] = 1;
		for (int i = 9; i <= 27; ++i)	a[i][i + 1] = 1;
		scanf("%I64d", &k);
		for (int i = 1; i <= 20; ++i, k /= 8)
			for (int j = 1; j <= k % 8; ++j)
				a[j][8 + i] = 1;
		for (int i = 1; i <= 28; ++i) {
			for (int j = 1; j <= 28; ++j)	printf("%d", a[i][j]);
			puts("");
		}
	}
	return 0;
}
