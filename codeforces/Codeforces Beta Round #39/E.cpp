#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n, m, k, M, a[N], c[N];
LL ans = 1;
bool rev;
int main() {
	cin >> n >> m >> k;
	if (n < m)	swap(n, m), rev = 1;
	for (int i = 1; i <= 1000; ++i)	a[i] = 1;
	while (k--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (rev)	swap(x, y);
		a[x] *= z, ++c[x];
	}
	scanf("%d", &M);
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		if (!p && !c[i])	p = 1;
		else if (c[i] == m && a[i] == 1)	ans = 0;
		else	for (int j = 1; j <= m - c[i] - 1; ++j)	ans = ans * 2 % M;	
	}
	if ((n + m) & 1)	ans = 0;
	cout << ans << endl;
	return 0;
}
