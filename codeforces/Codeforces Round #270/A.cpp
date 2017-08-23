#include <bits/stdc++.h>
using namespace std;
#define SZ(x)  (int)((x).size())
int main() {
	int n;
	scanf("%d", &n);
	if (n & 1)	printf("9 %d\n", n - 9);
	else printf("4 %d\n", n - 4);
	return 0;
}
