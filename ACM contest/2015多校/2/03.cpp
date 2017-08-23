#include <bits/stdc++.h>//construction
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
const int M = 1e6 + 5;
int w[3], b[3], d[M];
int main() {
	int T;
	read(T);
	while (T--) {
		for (int i = 0; i < 3; ++i)	read(w[i]);
		for (int i = 0; i < 3; ++i)	read(b[i]);
		if ((w[1] & 1) || (b[1] & 1)) {
			puts("-1");
			continue;
		}
		int sum = w[0] + w[1] + w[2];
		if (sum == 4) {
			puts("4\n1 2 0\n1 3 0\n2 3 1\n3 4 1");
			continue;
		}
		printf("%d\n", w[1] / 2 + w[2] + b[1] / 2 + b[2]);
		int t = 1;
		while (~w[2]) {
			printf("%d %d 0\n", t, t + 1);
			--w[2];
			++t;
		}
		++t;
		while (w[1] != 2) {
			printf("%d %d 0\n", t, t + 1);
			t += 2;
			w[1] -= 2;
		}
		t = 0;
		for (int i = 1; i <= sum; i += 2)	d[t++] = i;
		for (int i = 2; i <= sum; i += 2)	d[t++] = i;
		t = 0;
		while (~b[2]) {
			printf("%d %d 1\n", d[t], d[t + 1]);
			--b[2];
			++t;
		}
		++t;
		while (b[1] != 2) {
			printf("%d %d 1\n", d[t], d[t + 1]);
			t += 2;
			b[1] -= 2;
		}
	}
	return 0;
}
