#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 200005;
char s1[N], s2[N];
long long ans = 0;
struct Pal_tree {
	int nxt[N][26], fail[N], cnt[N], num[N], len[N], s[N], last, n, p;
	int insert(int l) {
		for (int i = 0; i < 26; ++i)	nxt[p][i] = 0;
		cnt[p] = num[p] = 0;
		len[p] = l;
		return p++;
	}
	void init() {
		p = last = n = 0;
		insert(0), insert(-1);
		s[n] = -1, fail[0] = 1;
	}
	inline int get_fail(int x) {
		while (s[n - len[x] - 1] != s[n])	x = fail[x];
		return x;
	}
	void add(int c) {
		s[++n] = c;
		int cur = get_fail(last);
		if (!nxt[cur][c]) {
			int now = insert(len[cur] + 2);
			fail[now] = nxt[get_fail(fail[cur])][c];
			nxt[cur][c] = now;
			num[now] = num[fail[now]] + 1;
		}
		last = nxt[cur][c];
		++cnt[last];
	}
	void gao() {
		for (int i = p - 1; i >= 0; --i)	cnt[fail[i]] += cnt[i];
	}
}a, b;
void dfs(int u, int v) {
	for (int i = 0; i < 26; ++i) {
		int x = a.nxt[u][i], y = b.nxt[v][i];
		if (x && y) {
			ans += (long long)a.cnt[x] * b.cnt[y];
			dfs(x, y);
		}
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt) {
		ans = 0;
		printf("Case #%d: ", tt) ;
		a.init(), b.init();
		scanf("%s%s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		for (int i = 0; i < l1; ++i)	a.add(s1[i] - 'a');
		for (int i = 0; i < l2; ++i)	b.add(s2[i] - 'a');
		a.gao(), b.gao();
		dfs(0, 0), dfs(1, 1);
		printf("%I64d\n", ans);
	}
	return 0;
}
