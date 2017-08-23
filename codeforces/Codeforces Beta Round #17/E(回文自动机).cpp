#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int N = 2000005, M = 51123987;
char S[N];
LL sum[N];
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
	LL add(int c) {
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
		return num[last];
	}
	LL gao() {
		LL t = 0ll;
		for (int i = p - 1; i >= 2; --i) {
			(cnt[fail[i]] += cnt[i]) %= M;
			(t += cnt[i]) %= M;
		}
		return t;
	}
}a;
int main() {
	int l;
	scanf("%d", &l);
	scanf("%s", S);
	a.init();
	for (int i = l - 1; i >= 0; --i)	sum[i] = (sum[i + 1] + a.add(S[i] - 'a')) % M;
	a.init();
	LL ans = 0ll;
	for (int i = 0; i < l; ++i) {
		(ans += a.add(S[i] - 'a') * sum[i + 1] % M) %= M;
	}
	LL tot = a.gao();
	printf("%I64d\n", ((tot * (tot - 1) / 2) % M - ans + M) % M);
	return 0;
}
