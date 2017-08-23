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
inline int V(int r, int h) {
	return r * r * h;
}
inline int SC(int r, int h) {
	return 2 * r * h;
}
inline int SD(int r) {
	return r * r;
}
const int N = 25;
int n, m, minv[N], mins[N], ans = INT_MAX;
void dfs(int num, int left, int s, int rnow, int hnow) {
	if (!num) {
		if (left == 0 && s < ans)	ans = s;
		return ;
	}
	if (left < minv[num] || s + mins[num] >= ans || 2 * left / rnow + s >= ans)	return;
	for (int i = rnow - 1; i >= num; --i) {
		if (num == m)	s = SD(i);
		int h = min((left - minv[num - 1]) / SD(i), hnow - 1);
		for (int j = h; j >= num; --j)	dfs(num - 1, left - V(i, j), s + SC(i, j), i, j);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 20; ++i) {
		minv[i] = minv[i - 1] + V(i, i);
		mins[i] = mins[i - 1] + SC(i, i);//²àÃæ»ý
	}
	dfs(m, n, 0, n + 1, n + 1);
	if (ans == INT_MAX)	puts("0");
	else printf("%d\n", ans);
	return 0;
}
