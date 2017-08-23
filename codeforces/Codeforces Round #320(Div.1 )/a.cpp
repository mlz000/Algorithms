#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (a < b) puts("-1");
	else if (a == b) printf("%d\n", a);
	else {
		int t1 = (a + b) / (2 * b), t2 = (a - b) / (2 * b);
		double ans = (double)(a + b) / (2 * t1);
		ans = min(ans, (double)(a - b) / (2 * t2));
		printf("%.12lf\n", ans);
	}
	return 0;
}
