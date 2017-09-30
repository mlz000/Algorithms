#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], cnt[N];
queue<int> q;
bool cg[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]), ++cnt[a[i]];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!cnt[i])	q.push(i), ++ans;
	printf("%d\n",ans);
	for (int i = 1; i <= n; ++i) {
		if (cnt[a[i]] > 1) { 
			int t = q.front();
			if (cg[a[i]] || t < a[i]) {
				printf("%d ", t);
				q.pop();
				--cnt[a[i]];
				continue;
			}
			else cg[a[i]] = 1, printf("%d ", a[i]);
		}
		else printf("%d ", a[i]);
	}
	return 0;
}
