#include <bits/stdc++.h>
using namespace std;
#define SZ(x)  (int)((x).size())
typedef long long LL;
const int N = 1005;
int a[N][N];
LL r[N], c[N], sr[N * 1000], sc[N * 1000];
priority_queue<LL> qr, qc;
int main() {
	int n, m, k, p;
	scanf("%d%d%d%d", &n, &m, &k, &p);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	for (int i = 1; i <= n; ++i)	qr.push(r[i]);
	for (int j = 1; j <= m; ++j)	qc.push(c[j]);
	for (int i = 1; i <= k; ++i) {
		int t = qr.top();
		qr.pop();
		sr[i] = sr[i - 1] + t;
		qr.push(t - m * p);
		t = qc.top();
		qc.pop();
		sc[i] = sc[i - 1] + t;
		qc.push(t - n * p);
	}
	LL ans = -1e18;
	for (int i = 0; i <= k; ++i)	ans = max(ans, sr[i] + sc[k - i] - (LL)i * (k - i) * p);
	printf("%I64d\n", ans);
	return 0;
}
