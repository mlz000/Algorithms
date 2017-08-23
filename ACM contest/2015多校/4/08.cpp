#include <bits/stdc++.h>//construction
using namespace std;
#define pb push_back
const int N = 1e5 + 5;
int a[N];
int main() {
	int k;
	while (~scanf("%d", &k)) {
		if (k <= 1e5) {
			printf("%d\n", k);
			for (int i = 1; i <= k; ++i)	printf("1 ");
			puts("");
		}
		else {
			bool ok = 0;
			int cnt1, cnt2, cnt3;
			for (int i = 1; i <= 1e5 && !ok; ++i)
				for (int j = 1; (i + j <= 1e5 && i + j + i * j <= k) && !ok; ++j) {
					int s = k - i - j - i * j;
					if (s % (i + j + 1) == 0) {
						s /= (i + j + 1);
						if (s < 0 || (i + j + s) > min(k, (int)1e5))	continue;
						ok = 1;
						cnt1 = i, cnt2 = j, cnt3 = s;
					}
				}
			printf("%d\n", cnt1 + cnt2 + cnt3);
			for (int i = 1; i <= cnt1; ++i)	printf("1 ");
			for (int i = 1; i <= cnt2; ++i)	printf("2 ");
			for (int i = 1; i <= cnt3; ++i)	printf("3 ");
			puts("");
		}
	}
	return 0;
}
