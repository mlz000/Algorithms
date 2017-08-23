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
const int N = 90005 << 1;
int tot, last, son[N][26], par[N], step[N], f[N], cnt[N], Q[N];
char s[N];
void insert(int x, int l) {
	int p = last, np = ++tot;
	step[np] = l, last = np;
	for (; !son[p][x] && ~p; p = par[p])	son[p][x] = np;
	if (p == -1)	return;
	int q = son[p][x];
	if (step[q] == step[p] + 1)	par[np] = q;
	else {
		step[++tot] = step[p] + 1;
		int nq = tot;
		memcpy(son[nq], son[q], sizeof(son[q]));
		par[nq] = par[q];
		par[np] = par[q] = nq;
		for (; son[p][x] == q && ~p; p = par[p])	son[p][x] = nq; 
	}
}
void gao() {
	for (int i = 1; i <= tot; ++i)    ++cnt[step[i]];
	for (int i = 1; i <= tot; ++i)    cnt[i] += cnt[i - 1];
	for (int i = 1; i <= tot; ++i)    Q[cnt[step[i]]--] = i;
	for (int i = tot; i >= 1; --i) {
		f[Q[i]] = 1;
		for (int j = 0; j < 26; ++j)
			f[Q[i]] += f[son[Q[i]][j]];
	}
}
int main() {
	par[0] = -1;
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i)	insert(s[i] - 'a', i + 1);	
	gao();
	int q;
	scanf("%d", &q);
	while (q--) {
		int k;
		scanf("%d", &k);
		int rt = 0;
		while (k) {
			for (int i = 0; i < 26; ++i) 
				if (son[rt][i]){
					if (f[son[rt][i]] >= k) {
						printf("%c", 'a' + i);
						rt = son[rt][i];
						--k;
						break;
					}
					else k -= f[son[rt][i]];
				}
		}
		puts("");
	}
	return 0;
}
