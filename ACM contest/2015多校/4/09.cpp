#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 1005;
char s[N][N];
struct data {
	int x, y;
	string S;
	data(){}
	data(int x, int y, string S):x(x), y(y), S(S){}
};
int n, m;
queue<data> q;
bool vis[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
inline bool check(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
vector<data> a, b;
data bfs(data st) {
	vis[st.x][st.y] = 1;
	q.push(st);
	bool zero = 0;
	if (s[st.x][st.y] == '0') {
		zero = 1;
		while (q.size()) {
			data t = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int x = t.x + dx[i];
				int y = t.y + dy[i];
				if (check(x, y)) {
					if (!vis[x][y] && s[x][y] == '0') {
						vis[x][y] = 1;
						data tt = data(x, y, "0");
						q.push(tt);
						b.pb(tt);
						if (x == n && y == m)	return tt;
					}
				}
			}
		}
	}
	for (int i = 0; i < b.size(); ++i) {
		if (zero)	b[i].S = "";
	}
	int Mn = 1000000;
	for (int i = 0; i < b.size(); ++i) {
		data t = b[i];
		Mn = min(Mn, n - t.x + m - t.y); 
	}
	for (int i = 0; i < b.size(); ++i) {
		data t = b[i];
		if(n - t.x + m - t.y == Mn)	a.pb(t);;
	}
	b.clear();
	if (!zero)	a.pb(st);
	while (1) {
		bool ok = 0;
		for (int i = 0; i < a.size(); ++i) {
			data u = a[i];
			if (u.x == n && u.y == m)	return u;
			for (int j = 0; j < 2; ++j) {
				int x = u.x + dx[j];
				int y = u.y + dy[j];
				if (check(x, y) && !vis[x][y]) {
					if (s[x][y] == '0')	ok = 1;
					string t = u.S;
					if (s[x][y] == '0')	t += "0";
					else t += "1";
					b.pb(data(x, y, t));
					vis[x][y] = 1;
				}
			}
		}
		a.clear();
		for (int j = 0; j < b.size(); ++j) {
			data u = b[j];
			string t = u.S;
			if (t[t.size() - 1] == '0')	t = "0";
			else t = "1";
			if ((ok && t == "0") || !ok)	a.pb(u);
		}
		b.clear();
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(vis, 0, sizeof(vis));
		a.clear(), b.clear();
		memset(s, 0, sizeof(s));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)	scanf("%s", s[i] + 1);
		if (n == 1 && m == 1) {
			printf("%c\n", s[1][1]);
			continue;
		}
		data t;
		t.x = 1, t.y = 1, t.S = (s[1][1] == '0' ? "0" : "1");
		data p = bfs(t);
		string ans = "";
		int sz = p.S.size();
		int pos = 0;
		for (; pos < sz; ++pos) {
			if (p.S[pos] == '0')	++pos;
			else break;
		}
		if (pos >= sz)	ans = "0";
		else {
			for (int i = pos; i < sz; ++i)	ans += p.S[i];
		}
		cout << ans << endl;
		while (q.size()) q.pop();
	}
	return 0;
}
