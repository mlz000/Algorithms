#include <bits/stdc++.h>
const int N = 1005;
int a[N], p[100];
bool v[100];
char s[N];
inline bool ok(int x, int st, int ed) {
	bool f = 0;
	f |= (x == a[st]);
	if (st < ed)	f |= (x == (a[st] * 10 + a[st + 1]));
	return f;
}
inline int num(int x) {
	if (x >= 1 && x <= 9)	return 1;
	else return 2;
}
inline bool can(int n, int st, int ed) {
	for (int i = 1; i <= n; ++i) {
		if (v[i])	continue;
		bool f = 0;
		for (int j = st; j <= ed; ++j) {
			if (ok(i, j, ed)) {
				f = 1;
				break;
			}
		}
		if (!f)	return 0;
	}
	return 1;
}
bool dfs(int x, int n, int l, int tot) {
	if (x == l)	return 1;
	for (int i = 1; i <= n; ++i) {
		if (v[i] || !ok(i, x + 1, l))	continue;
		v[i] = 1;
		p[tot] = i;
		if (can(n, x + num(i) + 1, l)) {
			if(dfs(x + num(i), n, l, tot + 1))	return 1;
		}
		v[i] = 0;
	}
	return 0;
}
int main() {	
	freopen("joke.in", "r", stdin);
	freopen("joke.out", "w", stdout);
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 1; i <= l; ++i)	a[i] = s[i - 1] - '0';
	int n = 1, cnt = 0;
	while (cnt < l) {
		cnt += num(n);
		++n;
	}
	--n;
	dfs(0, n, l, 1);
	for (int i = 1; i <= n; ++i)	printf("%d ", p[i]);	
	return 0;
}
	
