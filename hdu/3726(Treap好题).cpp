#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define pb push_back
const int N = 200005, M = 60005;
int w[N], f[N], u[M], v[M];
bool rem[M];
double ans1, ans2;
struct data {
	int type, x, p;
	data(){}
	data(int _type, int _x, int _p) {
		type = _type, x = _x, p = _p;
	}
};
vector<data> c;
struct Node {
	Node * ch[2];
	int w, s;
	long long fix;
	bool operator <(const Node &b)	const {
		return fix < b.fix;
	}
	int cmp(int x)	const {
		if (x == w)	return -1;
		return x < w ? 0 : 1;
	}
	void maintain() {
		s = 1;
		if (ch[0] != NULL)	s += ch[0] -> s;
		if (ch[1] != NULL)	s += ch[1] -> s;
	}
}*a[N], b[N], *tot = b;
queue<Node*> Q;
Node *newNode(int x) {
	Node * t;
	if (Q.size()) {
		t = Q.front();
		Q.pop();
	}
	else t = ++tot;
	t -> w = x, t -> s = 1, t -> fix = rand() * rand(), t -> ch[0] = t -> ch[1] = NULL;
	return t;
}
void rotate(Node* &o, int d) {
	Node* k = o -> ch[d ^ 1];
	o -> ch[d ^ 1] = k -> ch[d];
	k -> ch[d] = o;
	o -> maintain();
	k -> maintain();
	o = k;
}
void insert(Node* &o, int x) {
	if (o == NULL)	o = newNode(x);
	else {
		int d = (x < o -> w ? 0 : 1);
		insert(o -> ch[d], x);
		if (o -> ch[d] > o)	rotate(o, d ^ 1);
	}
	o -> maintain();
}
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
void Merge(Node* &p, Node* &q) {
	if (p -> ch[0] != NULL)	Merge(p -> ch[0], q);
	if (p -> ch[1] != NULL)	Merge(p -> ch[1], q);
	insert(q, p -> w);
	Q.push(p);
	p = NULL;
}
void add(int x) {
	int fu = find(u[x]);
	int fv = find(v[x]);
	if (fu != fv) {
		if (a[fu] -> s < a[fv] -> s) {
			f[fu] = fv;
			Merge(a[fu], a[fv]);
		}
		else {
			f[fv] = fu;
			Merge(a[fv], a[fu]);
		}
	}
}
void del(Node* &x) {
	if (x -> ch[0] != NULL)	del(x -> ch[0]);
	if (x -> ch[1] != NULL)	del(x -> ch[1]);
	Q.push(x);
	x = NULL;
}
void del2(Node* &o, int x) {
	if (o == NULL)	return;
	int d = o -> cmp(x);
	if (d == -1) {
		Node* t = o;
		if (o -> ch[0] != NULL && o -> ch[1] != NULL) {
			int d2 = (o -> ch[0] < o -> ch[1] ? 0 : 1);
			rotate(o, d2);
			del2(o -> ch[d2], x);
		}
		else {
			if (o -> ch[0] == NULL)	o = o -> ch[1];
			else o = o -> ch[0];
			Q.push(t);
			t = NULL;
		}
	}
	else del2(o -> ch[d], x);
	if (o != NULL)	o -> maintain();
}
int kth(Node* o, int k) {
	if (o == NULL || k <= 0 || o -> s < k)	return 0;
	int tmp = (o -> ch[1] == NULL ? 0 : o -> ch[1] -> s);
	if (k == tmp + 1)	return o -> w;
	else if (k <= tmp)	kth(o -> ch[1], k);
	else kth(o -> ch[0], k - tmp - 1);
}
void query(int x, int k) {
	++ans2;
	ans1 += kth(a[find(x)], k);
}
void change(int x, int v) {
	int fx = find(x);
	del2(a[fx], w[x]);
	insert(a[fx], v);
	w[x] = v;
}
int main() {
	int t = 0, n, m;
	while (scanf("%d%d", &n, &m) && n) {
		for (int i = 1; i <= n; ++i)	scanf("%d", &w[i]);
		srand(time(0));
		c.clear();
		memset(rem, 1, sizeof(rem));
		for (int i = 1; i <= m; ++i)	scanf("%d%d", &u[i], &v[i]);
		char s[10];
		while (1) {
			int flag, x, p, v;
			scanf("%s", s);
			if (s[0] == 'E')	break;
			scanf("%d", &x);
			if (s[0] == 'D') rem[x] = 0, flag = 0;//del
			else if (s[0] == 'Q') scanf("%d", &p), flag = 1; //query
			else if (s[0] == 'C') {
				scanf("%d", &v);
				p = w[x];
				w[x] = v;
				flag = 2;//change
			}
			c.pb(data(flag, x, p));
		}
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
			if (a[i] != NULL)	del(a[i]);
			a[i] = newNode(w[i]);//final map
		}
		for (int i = 1; i <= m; ++i) 
			if (rem[i])	add(i);		
		ans1 = 0.0, ans2 = 0.0;
		for (int i = c.size() - 1; i >= 0; --i) {
			if (c[i].type == 0)	add(c[i].x);
			else if (c[i].type == 1)	query(c[i].x, c[i].p);
			else change(c[i].x, c[i].p);
		}
		printf("Case %d: %.6lf\n", ++t, ans1 / ans2);
	}
	return 0;
}
