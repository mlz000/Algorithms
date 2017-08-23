#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
const int N = 10005;
char s[35];
int sz = 1, ch[N * 35][30], w[N * 35];
double x[10];
inline int idx(char c) {
	return c - 'a';
}
void insert(char *s, int l) {
	int u = 0;
	for (int i = 0; i < l; ++i) {
		int c = idx(s[i]);
		if (!ch[u][c]) {
			memset(ch[sz], 0, sizeof(ch[sz]));
			w[sz] = 1;
			ch[u][c] = sz++;
		}
		else w[ch[u][c]]++;
		u = ch[u][c];
	}
}
int find (const char *s, int l) {
	int u = 0;
	bool f = 1;
	for (int i = 0; i < l; ++i) {
		int c = idx(s[i]);
		if (!ch[u][c]) {
			f = 0;	
			break;
		}
		u = ch[u][c];
	}
	if (f)	return w[u];
	else return 0;
}
int main() {
	int n, m, k;
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(w, 0, sizeof(w));
		memset(ch[0], 0, sizeof(ch[0]));
		sz = 1;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s);
			int l = strlen(s);
			insert(s, l);
		}
		while (m--) {
			char ss[2005], tot = 0;
			scanf("%d", &k);
			while (k--) {
				double Min = 1e10;
				for (int i = 1; i <= 8; ++i) {
					scanf("%lf", &x[i]);
					Min = min(Min, x[i]);
				}
				int now = 0;
				for (int i = 1; i <= 8; ++i) {
					if (x[i] * 9500 <= Min * 10500 && x[i] >= Min)	continue;
					else	now |= 1 << (8 - i);
				}	
				ss[tot++] = now;
			}
			ans += find(ss, tot);
		}
		printf("%d\n", ans);
	}
	return 0;
}
