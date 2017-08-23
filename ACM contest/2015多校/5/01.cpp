#include <bits/stdc++.h>//SAM
using namespace std;
typedef unsigned long long ULL;
const int N = 90005 << 1, M = 26;
struct SAM {
	int tot, last, step[N], g[N], par[N], son[N][M], cnt[N], Q[N], ch[N];
	void init() {
		tot = last = 0;
		memset(par, 0, sizeof(par));
		par[0] = -1;
		memset(son, 0, sizeof(son));
	}
	void add(int x) {
		int p = last, np = ++tot;
		step[np] = step[p] + 1, last = np, ++g[np];//right
		ch[np] = x;
		for (; !son[p][x] && ~p; p = par[p])	son[p][x] = np;
		if (p == -1)	return;
		int q = son[p][x];
		if (step[q] == step[p] + 1)	par[np] = q;
		else {
			step[++tot] = step[p] + 1;
			ch[tot] = x;
			int nq = tot;
			memcpy(son[nq], son[q], sizeof(son[q]));
			par[nq] = par[q];
			par[np] = par[q] = nq;
			for (; son[p][x] == q && ~p; p = par[p])	son[p][x] = nq;
		}
	}
	void topo() {
		for (int i = 1; i <= tot; ++i)    ++cnt[step[i]];
		for (int i = 1; i <= tot; ++i)    cnt[i] += cnt[i - 1];
		for (int i = 1; i <= tot; ++i)    Q[cnt[step[i]]--] = i;		
	}
}A, B;
char s[N];
ULL dp[M];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%s", s);
		int l = strlen(s);
		A.init();
		for (int i = 0; i < l; ++i)	A.add(s[i] - 'a');
		scanf("%s", s);
		l = strlen(s);
		B.init();
		for (int i = l - 1; i >= 0; --i)	B.add(s[i] - 'a');
		for (int i = 1; i <= B.tot; ++i) dp[B.ch[i]] += B.step[i] - B.step[B.par[i]];
		ULL ans = 0;
		for (int i = 1; i <= A.tot; ++i) {
			ans += A.step[i] - A.step[A.par[i]];
			for (int j = 0; j < 26; ++j)
				if (!A.son[i][j])	ans += dp[j] * (A.step[i] - A.step[A.par[i]]);
		}
		cout << ans + 1 << endl;
	}
	return 0;
}
