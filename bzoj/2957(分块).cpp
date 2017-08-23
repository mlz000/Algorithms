#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const double eps = 1e-10;
int cnt[80];
double a[N], b[80][1300];
inline int read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int main() {
	int n, m, x, y;
	read(n), read(m);
	int S = (int)sqrt(n * log(n) / log(2) + 0.5), L = n / S + (n % S ? 1 : 0);
	while (m--) {
		read(x), read(y);
		a[x - 1] = (double)y / x;
		int bl = (--x) / S;
		cnt[bl] = 0;
		double now = 0.0;
		for (int i = bl * S; i < (bl + 1) * S && i < n; ++i)	
			if (a[i] > now + eps)	b[bl][cnt[bl]++] = a[i], now = a[i];
		now = 0.0;
		int ans = 0;
		for (int i = 0; i < L; ++i) {
			int l = 0, r = cnt[i] - 1;
			int t;
			while (l <= r) {
				int mid = l + r >> 1;
				if (b[i][mid] > now + eps)	t = mid, r = mid - 1;
				else l = mid + 1;
			}
			if (b[i][cnt[i] - 1] > now + eps)	ans += cnt[i] - t;
			now = max(now, b[i][cnt[i] - 1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
