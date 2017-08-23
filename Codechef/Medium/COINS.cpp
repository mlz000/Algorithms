#include <bits/stdc++.h>
using namespace std;
map<int, long long> mp;
long long dfs(long long n) {
	if (mp[n])	return mp[n];
	if (n <= 4)	return n;
	mp[n] = max(n, dfs(n / 2) + dfs(n / 3) + dfs(n / 4));
}
int main() {
	long long n;
	while (scanf("%lld", &n) != EOF) {
		printf("%lld\n", dfs(n));
	}
	return 0;
}

