#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 1e5 + 5;
int p[N][20], q[N][20], len[N], a[N];
bool check(int l, int r, int k) {
	int ll = len[r - l + 1];
	int t1 = max(p[l][ll], p[r - (1 << ll) + 1][ll]);
	int t2 = min(q[l][ll], q[r - (1 << ll) + 1][ll]);
	return t1 - t2 < k;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; ++i) {
			int k = 0;
			while((1 << (k + 1)) <= i)	++k;
			len[i] = k;
		}
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), p[i][0] = q[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; ++j)
			for (int i = 1; i + (1 << j) - 1 <=n ; ++i) {
				p[i][j] = max(p[i][j - 1], p[i + (1 << (j - 1))][j - 1]);
				q[i][j] = min(q[i][j - 1], q[i + (1 << (j - 1))][j - 1]);
			}
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			int l = i, r = n, t;
			while (l <= r) {
				int mid = l + r >> 1;
				if (check(i, mid, k))	t = mid, l = mid + 1;
				else r = mid - 1;
			}
			ans += t - i + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
