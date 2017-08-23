#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 100005;
int b[10], a[N];
bool check(int x) {
	memset(b, 0, sizeof(b));
	while (x) {
		++b[x % 10];
		x /= 10;
	}
	for (int i = 0; i <= 9; ++i)
		if (b[i] >= 2)	return 0;
	return 1;
}
int main() {
	int T;
	for (int i = 1; i <= 100000; ++i) {
		if (check(i))	a[i] = a[i - 1] + 1;
		else a[i] = a[i - 1];
	}
	scanf("%d", &T);
	while (T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", a[r] - a[l - 1]);
	}
	return 0;
}
