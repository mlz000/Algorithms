#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define F first
#define S second
const int N = 305;
int n, l[N], c[N];
map<int, int> mp;
map<int, int>::iterator it;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	scanf("%d", &l[i]);
	for (int i = 1; i <= n; ++i)	scanf("%d", &c[i]);
	mp[0] = 0;
	for (int i = 1; i <= n; ++i) 
		for (it = mp.begin(); it != mp.end(); it++) {
			int t = __gcd(it -> F, l[i]);
			if (!mp.count(t))	mp[t] = it -> S + c[i];
			else mp[t] = min(mp[t], it -> S + c[i]);
		}
	if (mp[1] == 0)	puts("-1");
	else printf("%d\n", mp[1]);
	return 0;
}
