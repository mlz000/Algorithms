#include <bits/stdc++.h>
using namespace std;
const int N = 18;
long long p[N], a[N], b[N];
void init() {
	p[0] = 1;
	for (int i = 1; i <= 17; ++i)	p[i] = p[i - 1] * 10;
	for (int i = 1; i <= 17; ++i)	a[i] = a[i - 1] * 9 + p[i - 1];
	for (int i = 2; i <= 17; ++i)	b[i] = b[i - 1] * 9 + p[i - 1] - 1; 
}
int main() {
	init();
	int T;
	scanf("%d", &T);
	long long n;
	while (T--) {
		scanf("%lld", &n);
		vector<int> d;
		long long t = n, x = 0, y = n * 10;
		while (t)	d.push_back(t % 10), t /= 10;
		reverse(d.begin(), d.end());
		int m = d.size();
		for (int i = 1; i <= 9; ++i) {
			for (int j = 0; j < m; ++j) {
				if (d[j] <= i)	x += d[j] * a[m - j - 1];
				else x += (d[j] - 1) * a[m - j - 1] + p[m - j - 1];
				if (d[j] == i) {
					long long tmp = 0;
					for (int k = j + 1; k < m; ++k)	tmp = tmp * 10 + d[k];
					x += tmp + 1;
					break;
				}
			}
		}
		x += b[m - 1];
		for (int i = 0; i < m; ++i) {
			if (!d[i]){
				long long tmp = 0;
				for (int j = i + 1; j < m; ++j)	tmp = tmp * 10 + d[j];
				x += tmp + 1;
				break;
			}
			else x += (d[i] - 1) * a[m - i - 1];
			if (i && d[i]) x += p[m - i - 1];
		}
		long long c = __gcd(x, y);
		printf("%lld/%lld\n", x / c, y / c);
	}
	return 0;
}

