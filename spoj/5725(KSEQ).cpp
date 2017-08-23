#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sq(LL x) {
	LL t = (LL)sqrt((double)x + 1);
	if (t * t > x)	--t;
	return t * t == x ? t : -100;
}
typedef long long LL;
int calc(LL x, LL y, LL z) {
	int ans = 0;
	x = 1ll + sq(1ll + 8ll * (x + y + z));
    if(x < 0 || x % 2)	return 0;
	x >>= 1ll;
	LL t = sq(x * x - 4ll * y), y1 = -100, y2 = -100;//y1 : b y2 : a + c
	if (t >= 0) {
		y1 = x - t, y2 = x + t;
		y1 = (y1 & 1) ? -100 : (y1 >> 1ll);
		y2 = (y2 & 1) ? -100 : (y2 >> 1ll);
	}
	if (y1 >= 0) {
		if (sq((x - y1) * (x - y1) - 4ll * z) > 0)	ans += 2;
		if (sq((x - y1) * (x - y1) - 4ll * z) == 0)	ans++;
	}
	if (y2 >= 0 && y1 != y2) {
		if (sq((x - y2) * (x - y2) - 4ll * z) > 0)	ans += 2;
		if (sq((x - y2) * (x - y2) - 4ll * z) == 0)	ans++;
	}
	return ans;
}
int main() {
	int T, x, y, z;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &x, &y, &z);
		printf("%d\n", calc(x, y, z));
	}
	return 0;
}
