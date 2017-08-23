#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;
int q[N];
LL l, H[N], W[N], f[N];
int main() {
	int n;
	scanf("%d%lld", &n, &l);
	multiset<LL> ms;
	LL sum = 0ll;
	int h = 1, r = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld%lld", &H[i], &W[i]);
		q[++r] = i - 1;
		while (h < r && H[i] >= H[q[r]]) {
			ms.erase(ms.find(f[q[r - 1]] + H[q[r]]));
			--r;
		}
		ms.insert(f[q[r]] + H[i]);
		q[r + 1] = i;
		for (sum += W[i]; sum > l; sum -= W[q[h]]) {
			ms.erase(ms.find(f[q[h]] + H[q[h + 1]]));
			if (++q[h] == q[h + 1])	++h;
			else ms.insert(f[q[h]] + H[q[h + 1]]);
		}
		f[i] = *ms.begin();
	}
	printf("%lld\n", f[n]);
	return 0;
}


