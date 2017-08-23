#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 500005;
LL a[N];
int main() {
	int T;
	read(T);
	while (T--) {
		int n, m, z, l;
		scanf("%d%d%d%d", &n, &m, &z, &l);
		a[1] = 0;
		for (int i = 2; i <= n; ++i)	a[i] = (a[i - 1] * m + z) % l;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans = (2 * a[i]) ^ ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
