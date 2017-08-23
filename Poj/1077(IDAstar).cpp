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
int b[9][2] = {
	{2, 2}, {0, 0}, {0, 1}, 
	{0, 2}, {1, 0}, {1, 1}, 
	{1, 2}, {2, 0}, {2, 1}
};
char s[5];
int a[5][5];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char op[] = {'u', 'l', 'r', 'd'};
char ss[10005];
bool f;
int h() {
	int t = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (a[i][j])	t += abs(i - b[a[i][j]][0]) + abs(j - b[a[i][j]][1]);
	return t;
}
void dfs(int x, int y, int now, int last, int step) {
	int t = h();
	if (f)	return;
	if (now + t > step)	return;
	if (!t && now == step) {
		f = 1;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (i + last == 3)	continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx <= 2 && ny >= 0 && ny <= 2)	{
			ss[now] = op[i];
			swap(a[x][y], a[nx][ny]);
			dfs(nx, ny, now + 1, i, step);
			if (f)	return;
			swap(a[x][y], a[nx][ny]);
		}
	}
}
int main() {
	int sx, sy;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			scanf("%s", s);
			if (s[0] == 'x')	a[i][j] = 0, sx = i, sy = j;
			else a[i][j] = s[0] - '0';
		}
	int ans;
	for (int i = 0; i <= 100; ++i) {
		dfs(sx, sy, 0, -1, i);
		if (f) {
			ans = i;
			break;
		}
	}
	if (!f)	puts("unsolvable");
	else for (int i = 0; i <= ans; ++i)	printf("%c", ss[i]);
	return 0;
}
