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
int n, a[N];
LL k;
int main() {
	int T;
	read(T);
	while (T--) {
		read(n);
		cin >> k;
		for (int i = 1; i <= n; ++i)	read(a[i]);
		LL now = 0, ans = 0;
		for (int i = 1; i <= n; ++i) {
			LL sum = a[i] - now;
			if (sum <= 0)	{
				now -= a[i];
				if (now > 0)	--now;
			}
			else {
				LL x = (sum - 1) / k + 1;
				ans += x;
				now += k * x - a[i];
				if (now > 0) --now;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
