//#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include <climits>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(LL &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 30005;
int f[N], sz[N], dep[N];
int find(int x) {
	int t = f[x];
	if (f[x] != x) {
		f[x] = find(f[x]);
		dep[x] += dep[t];
	}
	return f[x];
}
int main() {
	int n;
	for (int i = 1; i <= 30000; ++i) {
		f[i] = i;
		sz[i] = 1;
		dep[i] = 0;
	}
	scanf("%d", &n);
	while (n--) {
		char s[5];
		int x, y;
		scanf("%s", s);
		if (s[0] == 'M') {
			scanf("%d%d", &x, &y);
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				f[fy] = fx;
				dep[fy] += sz[fx];
				sz[fx] += sz[fy];
			}
		}
		else {
			scanf("%d", &x);
			printf("%d\n", sz[find(x)] - dep[x] - 1);
		}
	}
	return 0;
}
