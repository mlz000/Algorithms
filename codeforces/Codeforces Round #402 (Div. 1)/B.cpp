#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 5005;
map<string, int>mp;
char s1[20], s2[N], s3[20], op[10], mx[N], mn[N];
int a[N], b[N], c[N], d[2];
string val[N], o[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s%s%s", s1, s2, s2);
		mp[s1] = i;
		if (s2[0] == '0' || s2[0] == '1')	val[i] = s2;
		else {
			scanf("%s%s", op, s3);
			if (s2[0] == '?')	a[i] = 0;
			else a[i] = mp[s2];
			if (s3[0] == '?')	b[i] = 0;
			else b[i] = mp[s3];
			o[i] = op;
		}
	}
	for (int j = 0; j < m; ++j) {
		for (c[0] = 0; c[0] <= 1; ++c[0]) {
			d[c[0]] = 0;
			for (int i = 1, x, y; i <= n; ++i) {
				if (val[i] == ""){
					x = c[a[i]], y = c[b[i]];
					if (o[i] == "AND")	c[i] = x & y;
					else if (o[i] == "OR")	c[i] = x | y;
					else c[i] = x ^ y;
				}
				else c[i] = val[i][j] - '0';
				d[c[0]] += c[i];
			}
		}
		if (d[0] > d[1])	mx[j] = '0', mn[j] = '1';
		else if (d[0] < d[1])	mx[j] = '1', mn[j] = '0';
		else mx[j] = mn[j] = '0';
	}
	puts(mn), puts(mx);
	return 0;
}
