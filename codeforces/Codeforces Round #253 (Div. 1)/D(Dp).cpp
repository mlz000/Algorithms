#include <bits/stdc++.h>//Ê÷ÐÎdp nlogn 
using namespace std;
const int N = 1000005;
int p[N], sz[N], f[N], mx[N], mx2[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
		for (int x = i; x; x = p[x]) {
			int y = max(mx[x], mx2[x] + 1);
			if (y <= f[x])	break;
			f[x] = y;
			if (y > mx[p[x]])	mx[p[x]] = y;
			else if (y > mx2[p[x]])	mx2[p[x]] = y;
		}
		printf("%d ", max(mx[0], mx2[0]));
	}
	return 0;
}
