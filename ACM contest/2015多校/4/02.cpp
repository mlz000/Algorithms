#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 1e6 + 5;
int q1[N], q2[N], a[N];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
		if (n == 1) {
			puts("1");
			continue;
		}
		int mx1 = 2, mx2 = 2, ans1 = 2, ans2 = 2, h1 = 1, r1 = 2, h2 = 1, r2 = 2;
		q1[1] = q2[1] = a[1];
		q1[2] = q2[2] = a[2];
		for (int i = 3; i <= n; ++i) {
			if (a[i] - q1[r1] == q1[r1] - q1[r1 - 1]) {
				q1[++r1] = a[i];
				++ans1;
				mx1 = max(mx1, ans1);
			}
			else {
				while (h1 != r1)	++h1;
				q1[++r1] = a[i];
				ans1 = 2;
			}
			if ((LL)a[i] * q2[r2 - 1] == (LL)q2[r2] * q2[r2] && q2[r2] != 0) {
				q2[++r2] = a[i];
				++ans2;
				mx2 = max(mx2, ans2);
			}
			else {
				while (h2 != r2)	++h2;
				q2[++r2] = a[i];
				ans2 = 2;
			}
		}
		printf("%d\n", max(mx1, mx2));
	}
	return 0;
}
