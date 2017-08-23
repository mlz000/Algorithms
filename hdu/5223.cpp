#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
#pragma comment(linker, "/STACK:102400000,102400000") 
#define pb push_back
#define mp make_pair
#define F first
#define S second
const int N = 1005;
LL a[N];
inline LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a % b);
}
struct data {
	int l, r, x;
}Q[N];
int main() {
	int T, n, q;
	scanf("%d", &T);
	while (T--) {
		bool f = 1;
		memset(a, 0, sizeof(a));
		scanf("%d%d", &n, &q);
		int now = 0;
		while (q--) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			Q[++now].l = l;
			Q[now].r = r, Q[now].x = x;
			for (int i = l; i <= r; ++i) {
				if (!a[i])	{a[i] = x;continue;}
				a[i] = (LL)a[i] * x / gcd(a[i], x);
				if (a[i] > (int)1e9)	{f = 0;break;}
			}
		}
		for (int i = 1; i <= n; ++i)
			if (!a[i])	{a[i] = 1;}
		for (int i = 1; i <= now; ++i) {
			int l = Q[i].l, r = Q[i].r;
			int t = 0;
			for (int j = l; j <= r; ++j)
				t = gcd(a[j], t);
			if (t != Q[i].x){
				f = 0;
				break;
			}
		}
		if (!f)	puts("Stupid BrotherK!");
		else {
			for (int i = 1; i < n; ++i)
				printf("%I64d ", a[i]);
			printf("%I64d\n", a[n]);
		}
	}
	return 0;
}
