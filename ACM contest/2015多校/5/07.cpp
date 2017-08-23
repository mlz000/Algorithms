#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000") 
inline void read(int &t) {
	int f = 1;char c;
	while (c = getchar(), c < '0' || c > '9') if (c == '-')	f = -1;
	t = c - '0';
	while (c = getchar(), c >= '0' && c <= '9')	t = t * 10 + c - '0';
	t *= f;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int a, b;
		multiset<int> S;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a);
			if (a == 1) {
				scanf("%d", &b);
				S.insert(b);
			}
			else if (a == 2) {
				if (!S.empty())	S.erase(S.begin());
			}
			else {
				if (!S.empty())	printf("%d\n", *(--S.end()));
				else puts("0");
			}
		}
	}
	return 0;
}
