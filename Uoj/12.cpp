#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
int T;
LL g, l;
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%lld%lld", &g, &l);
		printf("%lld %lld\n", (LL)sqrt(1.0 * l / g) * g * 2, g + l);
	}
	return 0;
}
