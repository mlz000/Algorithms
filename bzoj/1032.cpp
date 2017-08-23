#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 505;
pair<int, int> a[N];
int n, f[N][N];
int main() {
	read(n);
	int now, j = 0;
	a[j].F = 1e5;
	for (int i = 1, x; i <= n; ++i) {
		read(x);
		if (x != a[j].F)	a[++j].F = x;
		++a[j].S;
	}
	memset(f, 0x3f, sizeof(f));
	n = j;
	for (int i = 1; i <= j; ++i) 
		f[i][1] = (a[i].S == 1 ? 2 : 1);
	for (j = 2; j <= n; ++j)
		for (int i = 1; i + j - 1 <= n; ++i) {
			if (a[i].F == a[i + j - 1].F)	
				f[i][j] = f[i + 1][j - 2] + (a[i].S + a[i + j - 1].S == 2 ? 1 : 0);
			for (int k = 1; k < j; ++k)	f[i][j] = min(f[i][j], f[i][k] + f[i + k][j - k]);
		}
	printf("%d\n", f[1][n]);
	return 0;
}
