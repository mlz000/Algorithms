#include <bits/stdc++.h>//บรฬโ
using namespace std;
#define mp make_pair
#define X first
#define Y second
typedef long long LL;
typedef pair<LL, int> pli;
const int N = 50005;
int a[N], c[N], p[N];
LL b[N], sb[N], r[N], rb[N];
pli num[N];
int get(int x) {
	int t = 0;
	for (; x; x -= x & -x)	t += c[x];
	return t;
}
void add(int x, int n) {
	for (;x <= n; x += x & -x)	++c[x];
}
LL gao(int n) {
	LL t = 0ll;
	for (int i = 0; i <= n; ++i)	c[i] = 0;
	for (int i = 0; i < n; ++i)	num[i].X = b[i], num[i].Y = i + 1;
	sort(num, num + n);
	for (int i = 0; i < n; ++i)	p[num[i].Y] = i + 1;
	for (int i = 1; i <= n; ++i) {
		add(p[i], n);
		t += i - get(p[i]);
	}
	return t;
}
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mini = 0;
		for (int i = 0; i < n; ++i)	{
			scanf("%d", &a[i]);
			b[i] = (i ? b[i - 1] : 0) + a[i];
			if (b[i] < b[mini])	mini = i;
		}
		LL s = b[n - 1];
		b[0] = 0;
		for (int i = 1; i < n; ++i)	b[i] = b[i - 1] + a[(mini + i) % n];
		long long ans = gao(n);
		sort(b, b + n);
		for (int i = 0; i < n; ++i) {
			LL ri = b[i] % s;
			r[i] = rb[i] = ri ? s - ri : ri;
		}
		sort(r, r + n);
		int rn = unique(r, r + n) - r;
		for (int i = 0; i <= n; ++i)	c[i] = 0;
		sb[0] = 0;
		for (int i = 0, j = 0; i < n; ++i) {
			long long cel = (b[i] + s - 1) / s;
			if (i < n - 1)	sb[i + 1] = sb[i] + cel;
			for (; j < n && b[j] + s < b[i]; ++j) {
				int x = lower_bound(r, r + rn, rb[j]) - r + 1;
				add(x, rn);
			}
			int x = lower_bound(r, r + rn, rb[i]) - r + 1; 
			ans += j * cel - sb[j] - get(x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
