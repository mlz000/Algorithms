#include <bits/stdc++.h>
using namespace std;
const int N=64, K=5005;
typedef pair<int, int> pii;
#define X first 
#define Y second 
int f[N],ans[K],sum[K << 1];
pii a[K];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0, x; i < k; ++i) {
		cin >> x;
		a[i] = make_pair(x, i);
	}
	for (int i = 1; i < 10000; ++i)	sum[i] = i / 1000 + i / 100 % 10 + i / 10 % 10 + i % 10;
	sort(a, a+k);
	int cnt = 0, now = 0;
	for (int i = 1; i <= n; ++i) {
		if (! f[i%63]) {
			++cnt;
			while (a[now].X == cnt)	ans[a[now++].Y] = i;
		}
		int t = i + sum[i / 10000] + sum[i % 10000];
		f[i % 63] = 0;
		f[t % 63] = 1;
	}
	cout << cnt << endl;
	for (int i = 0; i < k; ++i)	cout << ans[i] << endl;
	return 0;
}
