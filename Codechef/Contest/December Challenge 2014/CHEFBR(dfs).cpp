#include <bits/stdc++.h>
using namespace std;
int n, m;
long long b[30], tb[30], r[30];
long long sum, sumr[30], sp;
int init() {
	sum = 0;
	memset(b, 0, sizeof(b));
	memset(tb, 0, sizeof(tb));
	memset(r, 0, sizeof(r));
	memset(sumr, 0, sizeof(sumr));
	scanf("%d%d", &m, &n);
	long long sum2 = 0ll;
	for(int i = 1; i <= m; ++i)	scanf("%lld", &r[i]), sum2 += r[i];
	if ((sum2 % n) != 0) {
		puts("no");
		return -1;
	}
	if (sum2 == 0) {
		if (n <= m)	puts("yes");
		else puts("no");
		return -1;
	}
	for (int i = 1; i <= n; ++i) {
		tb[i] = b[i] = sum2 / n;
		sum += b[i];
	}
	return 0;
}
bool dfs(int dep, int pos) {
	if(dep < 1)	return 1;
	if(sp > sum - sumr[m])	return 0;
	for(int i = n; i >= pos; --i) {
		if (b[i] >= r[dep]) {
			b[i] -= r[dep];
			if (b[i] < r[1])	sp += b[i];
 			if(r[dep] == r[dep - 1]) {
				if(dfs(dep - 1, i))	return 1;
			}	
			else if(dfs(dep - 1, 1))	return 1;
			if(b[i] < r[1])	sp -= b[i];
			b[i] += r[dep];
		}
	}
	return 0;
}
void slove() {
	sort(tb + 1, tb + n + 1);
	sort(r + 1, r + m + 1);
	int po = 0;
	while (!r[po + 1] && po + 1 <= m)	++po;
	if (po == m) {
		puts("yes");
		return;
	}
	else {
		for (int i = 1; i <= m - po; ++i)	r[i] = r[i + po];
		m -= po;
	}
	for(int i = 1; i <= m; ++i)	sumr[i] = sumr[i - 1] + r[i];
	while(sum < sumr[m])	--m;
	for(int i = 1; i <= n; ++i) b[i] = tb[i];
	sp = 0;
	if(dfs(m, 1))	puts("yes");
	else puts("no");
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int f = init();
		if (f == -1)	continue;
		slove();
	}
	return 0;
}
