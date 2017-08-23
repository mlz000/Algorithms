#include <bits/stdc++.h>
using namespace std;
const int N = 500;
char s[N], ss[N];
int du[N], f[N];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
int nextInt(const char *s, int& p, int l) {
    int t = 0;
    while ((p < l)&&(!isdigit(s[p]))) ++p;
    if (p == l) return -1;
    while ((p < l) && isdigit(s[p]))
        t = t * 10 + s[p++] - '0';
    return t;
}
int main() {
    int m, n;
	fgets(s, N, stdin);
    while (s[3] != 'O') {
		int p = 0, l = strlen(s);
        m = nextInt(s, p, l), n = nextInt(s, p, l);
        memset(du, 0, sizeof(du));
        for (int i = 1; i <= n; ++i) f[i] = i;
        int ans = 0, x;
        for (int i = 0; i < n; ++i) {
            fgets(ss, N, stdin);
            p = 0, l = strlen(ss);
			while ((x = nextInt(ss, p, l)) >= 0) {
				++du[i], ++du[x], ++ans;
				int fi = find(i + 1), fx = find(x + 1);
				if (fi != fx)	f[fx] = fi;
			}
        }
        int odd = 0, ok = 1;
        for (int i = 0; i < n; ++i) {
            if (du[i] & 1)  ++odd;
        }
        for (int i = 1; i <= n; ++i) f[i] = find(i);
        for (int i = 1; i <= n; ++i) {
            if (f[i] != f[1] && du[i - 1])  ok = 0;
        }
        if (ok && ((!odd && !m) || (odd == 2 && m && (du[0] & 1) && (du[m] & 1))))    printf("YES %d\n", ans);
        else puts("NO");
	    fgets(s, N, stdin);
        fgets(s, N, stdin);
    }
    return 0;
}
