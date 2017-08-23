#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
const int N = 2000000;
crope a, b, t;
char s[N], rs[N], op[10];
int cur, len, n, x;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", op);
		if (op[0] == 'M')	scanf("%d", &cur);
		else if (op[0] == 'P')	--cur;
		else if (op[0] == 'N')	++cur;
		else if (op[0] == 'I') {
			scanf("%d", &x);
			len = a.length();
			for (int i = 0; i < x; ++i) {
				do {
					s[i] = getchar();
				}while (s[i] == '\n');
				rs[x - i - 1] = s[i];
			}
			rs[x] = s[x] = '\0';
			a.insert(cur, s);
			b.insert(len - cur, rs);
		}
		else if (op[0] == 'D') {
			scanf("%d", &x);
			len = a.length();
			a.erase(cur, x);
			b.erase(len -cur - x, x);
		}
		else if (op[0] == 'G')	putchar(a[cur]), puts("");
		else {
			scanf("%d", &x);
			len = a.length();
			t = a.substr(cur, x);
			a = a.substr(0, cur) + b.substr(len - cur - x, x) + a.substr(cur + x, len - cur - x);
			b = b.substr(0, len - cur - x) + t + b.substr(len - cur, cur);
		}
	}
	return 0;
}
