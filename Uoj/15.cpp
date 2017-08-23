#include <bits/stdc++.h>
using namespace std;
int ans[5][5] = {
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0, 0}
};
const int N = 205;
int a[N], b[N];
int main() {
	int n, na, nb;
	scanf("%d%d%d", &n, &na, &nb);
	for (int i = 0; i < na; ++i)	scanf("%d", &a[i]);
	for (int i = 0; i < nb; ++i)	scanf("%d", &b[i]);
	int t1 = 0, t2 = 0;
	for (int i = 0; i < n; ++i) {
		t1 += ans[a[i % na]][b[i % nb]];
		t2 += ans[b[i % nb]][a[i % na]];
	}
	printf("%d %d\n", t1, t2);
	return 0;
}
