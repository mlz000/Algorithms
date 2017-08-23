#include <bits/stdc++.h>
using namespace std;
const int N = 15;
long long f[N];
char s[N];
int n, a[15];
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '2')	++a[2];
		else if (s[i] == '3')	++a[3];
		else if (s[i] == '4') ++a[3], a[2] += 2;
		else if (s[i] == '5')	++a[5];
		else if (s[i] == '6')	++a[5], ++a[3];
		else if (s[i] == '7')	++a[7];
		else if (s[i] == '8')	++a[7], a[2] += 3;
		else if (s[i] == '9')	++a[7], a[3] += 2, ++a[2];
	}
	for (int i = 9; i >= 2; ) {
		if (a[i]) {
			printf("%d", i);
			--a[i];
		}
		else --i;
	}
	return 0;
}
