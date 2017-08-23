#include <bits/stdc++.h>//·Ö¿é
using namespace std;
typedef long long LL;
#define X first 
#define Y second
const int N = 100005;
int T, n, q, now[27], cnt[N][27];
char s[N];
inline LL gao(int x, int y) {
	if (y == 0)	return 1;
	else if (y == 1)	return x;
	else return x * x;
}
LL query(int l, int r, int op) {
	LL t = 0;
	for (int i = l; i <= r; ++i)
		for (int j = i + 1; j <= r; ++j) {
			bool f = 1;
			for (int k = 0; k < 26; ++k) {
				now[k] = cnt[j][k] - (i != 0 ? cnt[i - 1][k] : 0);
				if (now[k] & 1) {
					f = 0;
					break;
				}
			}
			if (f)	t += gao(j - i + 1, op);
		}
	return t;
}
void init() {
	memset(cnt, 0, sizeof(cnt));
	scanf("%s", s);
	n = strlen(s);
	scanf("%d", &q);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 26; ++j)	cnt[i][j] = cnt[i - 1][j];
		++cnt[i][s[i] - 'a'];
	}
    LL A = 0 ; // initialising first key 
    LL B = 0 ; // initialising second key
	int X, Y, L, R, type;
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d%d", &X, &Y, &type); 
        L = ( X + A ) % n + 1; // decoding L
        R = ( Y + B ) % n + 1; // decoding R
        if (L > R)	swap(L, R);
		L--, R--;
		LL ans = query(L, R, type);
		cout << ans << endl;
	    A = B;     // updating key A 
   	    B = ans;   // updating key B 
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		init();
	}
	return 0;
}

