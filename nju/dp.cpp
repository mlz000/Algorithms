#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int f[1000005];
int dfs(int n) {
	if (n <= 6)	return n;
	if (f[n])	return f[n];
	return n / 7 * 7 + dfs(n % 7 + n / 7);
}
int main () {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", dfs(n));
	}
	return 0;
}
