#include <bits/stdc++.h>//Matrix-tree
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 16, M = 998244353;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int n, p[N], g[N][N], a[N][N], dp[(1 << N) + 5][N], f[(1 << N) + 5];
void exgcd(int a, int b, int &x, int &y) {
    if (b) {
        exgcd(b, a % b, y, x);
        y -= a / b * x ;
    } 
	else {
        x = 1;
        y = 0;
    }
}
int inv(int a){
    int x, y, b = M;
    exgcd(a, b, x, y);
    if (x < 0) x += M;
    return x;
}
int gauss(int n) {
    int res = 1;
	--n;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[j][i]) {
                if (i != j) {
                    for (int k = i; k < n; ++k)	swap(a[i][k], a[j][k]);
                    res = -res;
                    if (res < 0) res += M ;
                }
                break;
            }
        }
        if (!a[i][i]) return 0 ;
        for (int j = i + 1; j < n; ++j) {
            int mut = (LL)a[j][i] * inv(a[i][i]) % M;
            for (int k = i; k < n; ++k) {
                a[j][k] -= (LL)a[i][k] * mut % M;
                if (a[j][k] < 0) a[j][k] += M;
            }
        }
    }
	for (int i = 0; i < n; ++i)	res = (LL)res * a[i][i] % M;
    return res;
}
int gao() {
	memset(f, 0, sizeof(f));
	int inv2 = inv(2);
	for (int s = 0; s < n; ++s) {
		memset(dp, 0, sizeof(dp));
		dp[1 << s][s] = 1;
		for (int i = 0; i < 1 << n; ++i) 
			for (int j = 0; j < n; ++j)
				if (dp[i][j]) {
					for (int k = s + 1; k < n; ++k)
						if (!(i >> k & 1) && g[j][k])	(dp[i | (1 << k)][k] += dp[i][j]) %= M;
					if (g[j][s])	(f[i] += dp[i][j]) %= M;
				}
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (g[i][j])	(f[(1 << i) | (1 << j)] += M - 1) %= M;
	for (int i = 0; i < 1 << n; ++i)	f[i] = 1ll * f[i] * inv2 % M;
	int ans = 0;
	for (int mask = 0; mask < 1 << n; ++mask) 
		if (f[mask]) {
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)	
					a[j][k] = 0;
			for (int j = 0; j < n; ++j)	p[j] = -1;
			for (int j = 0; j < n; ++j)
				if (mask >> j & 1)	p[j] = 0;
			int now = 1;
			for (int j = 0; j < n; ++j)
				if (p[j] == -1)	p[j] = now++;
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					if (g[j][k] && p[j] != p[k]) {
						++a[p[j]][p[j]];
						--a[p[j]][p[k]];
					}
			(ans += 1ll * f[mask] * gauss(now) % M) %= M;
		}
	return ans;
}
int main() {
	int m;
	while (~scanf("%d%d", &n, &m)) {
		memset(g, 0, sizeof(g));
		for (int i = 1, x, y; i <= m; ++i) {
			scanf("%d%d", &x, &y);
			--x, --y;
			g[x][y] = g[y][x] = 1;
		}
		printf("%d\n", gao());
	}
	return 0;
}
