#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#pragma comment(linker, "/STACK:1024000000,1024000000") 
typedef long long LL;
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 1e6 + 5, M = 10;
int f[N], sum[N][M], a[M], g[M][M];
void init(){
	for (int i = 2; i <= 1000000; ++i) {
		if (f[i])	continue;
		for (int j = i; j <= 1000000; j += i)	++f[j];
	}
	for (int i = 2; i <= 1000000; ++i)
		for (int j = 1; j <= 7; ++j) {
			if (j != f[i])	sum[i][j] = sum[i - 1][j];
			else sum[i][j] = sum[i - 1][j] + 1;
		}
	for (int i = 1; i <= 7; ++i)
		for (int j = 1; j <= 7; ++j)
			g[i][j] = __gcd(i, j);
}
int main() {
 	init();
	int T;
	read(T);
	while (T--) {
		int l, r;
		read(l), read(r);
		for (int i = 1; i <= 7; ++i)
			a[i] = sum[r][i] - sum[l - 1][i];
		int ans = 0;
		for (int i = 1; i <= 7; ++i) {
			if (a[i] >= 2)	ans = max(ans, i);
			for (int j = i + 1; j <= 7; ++j) {
				if (a[i] && a[j])	ans = max(ans, g[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
