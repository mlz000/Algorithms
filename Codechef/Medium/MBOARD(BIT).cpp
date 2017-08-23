#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 500005;
pii last[2][N];
#define X first
#define Y second
int n, q, t[2][2][N];
int get(int t[N], int pos) {
	int tmp = 0;
	for (; pos; pos -= pos & -pos)	tmp += t[pos];
	return tmp;
}
int query(int a, int id) {
	int pos = last[a][id].X, col = last[a][id].Y;
	int cnt = get(t[a ^ 1][col ^ 1], q - pos);
	return col == 0 ? n - cnt : cnt;
}
void add(int t[N], int pos, int c) {
	for (;pos <= q + 1; pos += pos & -pos)	t[pos] += c;
}
void change(int a, int id, int x, int tt) {
	if (last[a][id].X != -1) {
		add(t[a][last[a][id].Y], q - last[a][id].X, -1);
	}
	last[a][id] = make_pair(tt, x);
	add(t[a][x], q - tt, 1);
}
int main() {
	char s[15];
	scanf("%d%d", &n, &q);
	for (int i = 0; i < 2; ++i)
		for (int j = 1; j <= n; ++j)
			last[i][j] = make_pair(-1, 0);
	for (int i = 0; i < q; ++i) {
		int id, x;
		scanf("%s", s);
		int a = s[0] == 'R', b = s[3] == 'Q'; //R : 1, C : 0
		if (b) {
			scanf("%d", &id);
			printf("%d\n", query(a, id));
		}
		else {
			scanf("%d%d", &id, &x);
			change(a, id, x, i);
		}
	}
	return 0;
}
