//Trie
struct Trie{
	int ch[N][M];
	int w[N];
	int sz;
	void clear()	{sz=1,memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c)	{return c-'a';}
	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				w[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		w[u]=v;
	}
	void find(const char *s,int len,vector<int>&ans){
		int u=0;
		for(int i=0;i<len;++i){
			if(s[i]=='\0')	break;
			int c=idx(s[i]);
			if(!ch[u][c])	break;
			u=ch[u][c];
			if(w[u])	ans.push_back(w[u]);
		}
	}
}trie;
//AC自动机
struct AC{
	int ch[N][M],w[N],last[N],p[N],sz;
	inline int idx(char c)	{return c-'a';}
	inline void clear(){sz=1;memset(ch[0],0,sizeof(ch[0]))}
	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				w[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		w[u]=v;
		mp[string(s)]=v;
	}
	void getfail(){
		p[0]=0;
		queue<int>q;
		for(int c=0;c<M;++c){
			int u=ch[0][c];
			if(u)	{p[u]=0;q.push(u);last[u]=0;}
		}
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i=0;i<26;++i){
				int v=ch[u][i];
				if(!v)	{ch[u][i]=ch[p[u]][i];continue;}
				q.push(v);
				p[v]=ch[p[u]][i];
				last[v]=w[p[v]]?p[v]:last[p[v]];
			}
		}
	}
	void print(int x){
		if(x){
			printf("%d: %d\n",x,w[x]);
			print(last[x]);
		}
	}
	void find(char *s){
		int n=strlen(s);
		int u=0;
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			u=ch[u][c];
			if(w[u])	print(u);
			else if(last[u])	print(last[u]);
		}
	}
}ac;
//Manacher
int calc(){
	scanf("%d%s",&n,s2);
	s1[m]='?',s1[++m]='#';
	for(int i=0;i<n;++i)	s1[++m]=s2[i],s1[++m]='#';
	int mx=0,id=0;
	for(int i=1;i<=m;++i){
		if(mx>i)	p[i]=min(p[2*id-i],mx-i);
		else	p[i]=1;
		for(;s1[i+p[i]]==s1[i-p[i]];p[i]++);
		if(i+p[i]>mx){
			mx=i+p[i];
			id=i;
		}
	}
}
//SA
struct suffixarray{
	int n, arr1[N], arr2[N], sa[N], rk[N], hei[N], c[N];
	int *x = arr1, *y = arr2;
	int m = 26;
	for (int i = 1; i <= n; ++i) ++c[x[i] = s[i] - 'a' + 1];
	for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
	for (int i = 1; i <= n; ++i) sa[c[x[i]]--] = i;
	for (int k = 1; k < n; k <<= 1) {
		int yt = 0;
		for (int i = n - k + 1; i <= n; ++i) y[++yt] = i;
		for (int i = 1; i <= n; ++i)
			if (sa[i] - k >= 1) y[++yt] = sa[i] - k;
		for (int i = 1; i <= m; ++i) c[i] = 0;
		for (int i = 1; i <= n; ++i) ++c[x[i]];
		for (int i = 1; i <= m; ++i) c[i] += c[i - 1];
		for (int i = n; i >= 1; --i) sa[c[x[y[i]]]--] = y[i];
		m = 0;
		for (int i = 1; i <= n; ++i) {
			int u = sa[i], v = sa[i - 1];
			if (i == 1 || x[u] != x[v] || x[u + k] != x[v + k]) ++m;
			y[u] = m;
		}
		if (m >= n) break;
		swap(x, y);
	}
	for (int i = 1; i <= n; ++i) rk[sa[i]] = i;
	for (int i = 1, h = 0; i <= n; ++i) {
		h = max(h - 1, 0);
		if (rk[i] == 1) continue;
		int j = sa[rk[i] - 1];
		while (i + h <= n && j + h <= n && s[i + h] == s[j + h]) ++h;
		hei[rk[i]] = h;
	}
}SA;
//SAM
void add(int x) {
	int p = last, np = ++tot;
	step[np] = step[p] + 1, last = np, ++g[np];//right
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
int main(){
	par[0] = -1;
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;++i)	ins(s[i]-'a');
	for (int i = 1; i <= tot; ++i)    ++cnt[step[i]];
    for (int i = 1; i <= tot; ++i)    cnt[i] += cnt[i - 1];
    for (int i = 1; i <= tot; ++i)    Q[cnt[step[i]]--] = i;
}
//回文自动机
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
	void work() {
		for (int i = p - 1; i >= 0; --i)	cnt[fail[i]] += cnt[i];
	}
};
