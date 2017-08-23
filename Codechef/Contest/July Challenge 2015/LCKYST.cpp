#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5;
int a[N];
int main() {
	int n;
	read(n);
	for (int i = 1; i <= n; ++i)	read(a[i]);
	for (int j = 1; j <= n; ++j) {
		int cnt = 0, cnt2 = 0;
		while (a[j] % 10 == 0)	a[j] /= 10, ++cnt2;
		while (a[j] % 5 == 0)	a[j] /= 5, ++cnt;
		LL t = a[j];
		for (int i = 1; i <= cnt2; ++i)	t *= 10;
		for (int i = 1; i <= cnt / 2 + (cnt & 1); ++i)	t *= 4;
		for (int i = 1; i <= cnt; ++i)	t *= 5;
		printf("%lld\n", t);
	}
	return 0;
}
