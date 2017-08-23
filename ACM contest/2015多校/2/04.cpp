#include <bits/stdc++.h>//greedy
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 1e5 + 5;
int a[N], b[N];
LL dp1[N], dp2[N];
int main() {
	int T;
	read(T);
	while (T--) {
		int L, n, k;
		read(L), read(n), read(k);
		int c1 = 0, c2 = 0;
		for (int i = 1, x, y; i <= n; ++i) {
			read(x), read(y);
			for (int j = 1; j <= y; ++j) {
				if (x * 2 < L)	a[++c1] = x;
				else b[++c2] = L - x;
			}
		}
		sort(a + 1, a + c1 + 1);
		sort(b + 1, b + c2 + 1);
		for (int i = 1; i <= c1; ++i) {
			if (i <= k)	dp1[i] = a[i];
			else dp1[i] = dp1[i - k] + a[i];
		}
		for (int i = 1; i <= c2; ++i) {
			if (i <= k)	dp2[i] = b[i];
			else dp2[i] = dp2[i - k] + b[i];
		}
		LL ans = (dp1[c1] + dp2[c2]) * 2; 
		for (int i = 0; i <= c1 && i <= k; ++i) {
			int l = c1 - i, r = max(0, c2 - (k - i));
			ans = min(ans, L + (dp1[l] + dp2[r]) * 2);
		}
		cout << ans << endl;
		for (int i = 1; i <= c1; ++i)	dp1[i] = 0;
		for (int i = 1; i <= c2; ++i)	dp2[i] = 0;
	}
	return 0;
}
