#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s[] = {"Stas", "Missing", "Masha"};
int n, dp[10005][40];
int f(int a, int b) {
	if (~dp[a][b])	return dp[a][b];
	if (a == 1 && (1ll << b) >= n)	return dp[a][b] = 1;
	if (b == 1 && (LL)a * a >= n)	return dp[a][b] = (n - a) & 1 ? 0 : 2;
	if (pow(a, b) + 1e-6 >= n)	return dp[a][b] = 2;
	return dp[a][b] = 2 - min(f(a + 1, b), f(a, b + 1));
}
int main() {
	int a, b;
	memset(dp, -1, sizeof(dp));
	cin >> a >> b >> n;
	cout << s[f(a, b)] << endl;
	return 0;
}
