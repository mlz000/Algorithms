#include <bits/stdc++.h>
using namespace std;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 100005;
int a[N], p1[400][N], p2[400][N], f1[400][N], f2[400][N], hash[N], pos[N];
int main() {
	int n, m, k;
	read(n), read(m), read(k);
	int S = sqrt(n);
	int B = n / S + (n % S != 0);
	for (int i = 0; i < n; ++i)	read(a[i]);
	for (int i = 0; i < B; ++i)
		for (int j = i * S; j < n; ++j) {
			if (!p2[i][a[j]])	p2[i][a[j]] = j + 1;
			f2[i][j] = max(f2[i][j - 1], j + 1 - p2[i][a[j]]);
		}
	for (int i = B - 1; i >= 0; --i)
		for (int j = min((i + 1) * S, n) - 1; j >= 0; --j) {
			if (!p1[i][a[j]])	p1[i][a[j]] = j + 1;
			f1[i][j] = max(f1[i][j + 1], p1[i][a[j]] - j - 1);
		}
	while (k--) {
		int l, r;
		read(l), read(r);
		--l, --r;
		int bl = l / S, br = r / S, ans = 0;
		if (bl == br) {
			for (int i = l; i <= r; ++i) {
				if (hash[a[i]] == k) ans = max(ans, i - pos[a[i]]);
				else hash[a[i]] = k, pos[a[i]] = i;
			}
		}
		else {
			bl += (l % S != 0), br -= (r % S != S - 1); 
			ans = max(f2[bl][r], f1[br][l]);
			for (int i = l; i < bl * S; ++i) {
				if (hash[a[i]] == k) ans = max(ans, i - pos[a[i]]);
				else hash[a[i]] = k, pos[a[i]] = i;			
			}
			for (int i = (br + 1) * S; i <= r; ++i) {
				if (hash[a[i]] == k) ans = max(ans, i - pos[a[i]]);
				else hash[a[i]] = k, pos[a[i]] = i;				
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
