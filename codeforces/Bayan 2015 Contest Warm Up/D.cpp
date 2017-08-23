#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], next[N];
map <int, long long> p;
int main() {
	int n, q, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), next[i] = i + 1;
	for (int i = n; i >= 1; --i){
		int ago = i;
		for (int j = i; j <= n; j = next[j]) {
			a[j] = __gcd(a[j], a[ago]);
			if (a[j] == a[ago])	next[ago] = next[j];
			ago = j;
			p[a[j]] += (next[j] - j);
		}
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &x);
		printf("%I64d\n", p[x]);
	}
	return 0;
}
