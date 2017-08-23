#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 105, M = 1e6 + 5, mod1 = 9973, mod2 = 9999973;
int n, m, a[N], b[N], f[mod1];
vector<int> ans;
inline void read(int &a, int &b){
    char c = getchar(); 
	a = 0, b = 0;    
	int flg = 0;
    while(c < '0' || c > '9')   flg |= c == '-', c = getchar();
    while(c >= '0' && c <= '9') a = (a * 10ll + c - '0') % mod1,b = (b * 10ll + c - '0') % mod2, c = getchar();
    if(flg) a = -a,b = -b;
}
bool check(int x, int c[], int mod) {
	int now = 0;
	for (int i = n; i >= 0; --i)	now = ((long long)now * x + c[i]) % mod;  
	return now == 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; ++i)	read(a[i], b[i]);
	for (int i = 0; i <= m && i < mod1; ++i)	f[i] = check(i, a, mod1);
	for (int i = 1; i <= m; ++i) 
		if (f[i % mod1] && check(i, b, mod2))	ans.pb(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)	printf("%d\n", ans[i]);
	return 0;
}
