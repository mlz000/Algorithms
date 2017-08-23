#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool f[N];
int main() {
	for (int i = 2; i < N; ++i)
		if (!f[i]) {
			for (int j = i + i; j < N; j += i)	f[j] = 1;
		}
	int n;
	scanf("%d", &n);
	if (n <= 2) {
		puts("1");
		for (int i = 1; i <= n; ++i)	printf("1 ");
	}
	else {
		puts("2");
		for (int i = 1; i <= n; ++i) {
			if (f[i + 1]) printf("2 ");
			else printf("1 ");
		}
	}
	return 0;
}
