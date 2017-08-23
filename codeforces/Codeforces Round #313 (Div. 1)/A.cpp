#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int N = 10;
int a[N];
inline int f(int n) { 
	return n * n; 
}
int main() {
	for (int i = 0; i < 6; ++i) scanf("%d", &a[i]);
	int sum = a[0] + a[1] + a[2];
	int ans = f(sum) - f(a[0]) - f(a[2]) - f(a[4]);
	printf("%d\n", ans);
	return 0;
}
