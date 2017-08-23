#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 131;
unsigned long long p[N], hash1[N], hash2[N];
char s1[N], s2[N];
int l1, l2;
bool check(int p1, int p2, int p3, int p4) {
	return (hash1[p2] - hash1[p1 - 1] * p[p2 - p1 + 1] == hash2[p4] - hash2[p3 - 1] * p[p4 - p3 + 1]);
}
int main() {
	int T;
	scanf("%d", &T);
	p[0] = 1;
	for (int i = 1; i <= (int)1e5; ++i)	p[i] = p[i - 1] * M;
	for (int tt = 1; tt <= T; ++tt) {
		printf("Case #%d: ", tt);
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		l1 = strlen(s1 + 1);
		l2 = strlen(s2 + 1);
		hash1[0] = hash2[0] = 0;
		for (int i = 1; i <= l1; ++i)	hash1[i] = hash1[i - 1] * M + s1[i] - 'a';
		for (int i = 1; i <= l2; ++i)	hash2[i] = hash2[i - 1] * M + s2[i] - 'a';
		int p = -1;
		for (int i = 1; i <= l1 - l2 + 1; ++i) {
			if (l1 < l2)	break;
			if (l2 <= 2) {
				p = i - 1;
				break;
			}
			int l = i, r = i + l2 - 1, ans1 = -1;
			while (l <= r) {
				int mid = l + r >> 1;
				if (check(i, mid, 1, mid - i + 1)) {
					ans1 = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			l = i, r = i + l2 - 1;
			int ans2 = -1;
			while (l <= r) {
				int mid = l + r >> 1;
				if (check(mid, i + l2 - 1, mid + 1 - i, l2))	 {
					ans2 = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			if (ans1 == -1 && ans2 == -1) {
				if (check(i + 1, i + l2 - 2, 2, l2 - 1)) {
					p = i - 1;
					break;
				}
			}
			else if (ans1 != -1 && ans2 != -1) {
				if (ans2 - ans1 - 1 <= 2) {
					p = i - 1;
					break;
				}
				if (check(ans1 + 2, ans2 - 2, ans1 - i + 3, ans2 - i - 1)) {
					p = i - 1;
					break;
				}
			}
			else {
				if (ans1 == -1) {
					if (ans2 <= i + 2) {
						p = i - 1;
						break;
					}
					if (check(i + 1, ans2 - 2, 2, ans2 - i - 1))	 {
						p = i - 1;
						break;
					}
					if (check(i + 2, ans2 - 1, 3, ans2 - i)) {
						p = i - 1;
						break;
					}
				}
				else {
					if (ans1 >= i + l2 - 3) {
						p = i - 1;
						break;
					}
					if (check(ans1 + 2, i + l2 - 2, ans1 - i + 3, l2 - 1)) {
						p = i - 1;
						break;
					}
					if (check(ans1 + 1, i + l2 - 3, ans1 - i + 2, l2 - 2)) {
						p = i - 1;
						break;
					}
				}
			}
		}
		printf("%d\n", p);
	}
	return 0;
}
