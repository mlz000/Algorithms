#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 100005;
char S[N];
long long sum[N];
long long ans;
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
	int add(int c) {
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
	void gao() {
		for (int i = p - 1; i >= 0; --i)	cnt[fail[i]] += cnt[i];
	}
}a;
int main() {
	while (scanf("%s", S) != EOF) {
		a.init();
		memset(sum, 0, sizeof(sum));
		int l = strlen(S);
		ans = 0;
		for (int i = l - 1; i >= 0; --i) sum[i] = sum[i + 1] + a.add(S[i] - 'a');
		a.init();
		for (int i = 0; i < l; ++i) {
			ans += sum[i + 1] * a.add(S[i] - 'a');
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

