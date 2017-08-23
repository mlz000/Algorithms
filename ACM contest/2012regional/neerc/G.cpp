#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 10005;
long long n, dp[N][2];
int k;
int a[10005];
long long gao(int l, int lim) {
	if (l == -1)	return 1;
	if (~dp[l][lim])	return dp[l][lim];
	int x = lim ? a[l] : k - 1;
	if (l & 1)	x = 0;
	long long t = 0;
	for (int i = 0; i <= x; ++i) {
		t += gao(l - 1, lim && i == a[l]); 
	}
	return	dp[l][lim] = t;
}
int main() {
	freopen("great.in", "r", stdin);
	freopen("great.out", "w", stdout);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	int l = 0;
	while (n) {
		a[l++] = n % k;
		n /= k;
	}
	cout << gao(l - 1, 1) << endl;
	return 0;
}

