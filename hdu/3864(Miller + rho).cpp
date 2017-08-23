#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
using namespace std;
typedef long long LL;
#define pb push_back
LL factor[1000005];
int tol;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 61, 24251};
LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a % b);
}
LL mul(LL a, LL b, LL p) {
	LL t = (a * b - (LL)((long double)a * b / p  + 0.05) * p);
	return t < 0 ? t + p : t;
}
LL P(LL x, LL y, LL p) {
	if (y == 0)	return 1 % p;
	LL t = 1ll;
	x = x % p;
	for (; y; y >>= 1ll) {
		if (y & 1ll)	t = mul(t, x, p);
		x = mul(x, x, p);
	}
	return t;
}
bool check(LL a, LL n, LL r, LL s) {
	LL t = P(a, r, n), p = t;
	for (int i = 1; i <= s; ++i) {
		t = mul(t, t, n);
		if (t == 1 && p != 1 && p != n - 1)	return 1;
		p = t;
	}
	if (t != 1)	return 1;
	return 0;
}
LL Pollard_rho(LL n, LL c) {
	LL k = 2, x = rand() % n, y = x, p = 1;
	for (LL i = 1; p == 1; ++i){
		++i;
		x = (mul(x, x, n) + c) % n;
		p = y > x ? y - x : x - y;
		p = gcd(p, n);
		if (i == k)	y = x, k <<= 1ll;
	}
	return p;
}
bool Miller_Rabin(LL n) {
	if (n < 2)	return 0;
	if (n == 2)	return 1;
	if ((n % 2) == 0)	return 0;
	LL r = n - 1, s = 0;
	while ((r % 2) == 0) r >>= 1ll, ++s;
	for (int i = 0; i < 10; ++i) {
		if (p[i] >= n)	continue;
		if (check(p[i], n, r, s))	return 0;
	}
	return 1;
}
void find(LL n) {
	if (Miller_Rabin(n)) {
		factor[tol++] = n;
		return;
	}
	LL t = n;
	while (t >= n)	t = Pollard_rho(t, rand() % (n - 1) + 1);
	find(t);
	find(n / t);
}
int main() {
	LL n;
	srand(time(NULL));
    while(~scanf("%I64d",&n)) {
        if(n == 1){
            printf("is not a D_num\n");
            continue;
        }
        tol = 0;
        find(n);
        if(tol != 2 && tol != 3){
            printf("is not a D_num\n");
            continue;
        }
        sort(factor, factor + tol);
        if(tol == 2 && factor[0] != factor[1]){
            printf("%I64d %I64d %I64d\n",factor[0], factor[1], n);
        }
        else if(tol == 3 && factor[0] == factor[1] && factor[1] == factor[2]){
            printf("%I64d %I64d %I64d\n",factor[0], factor[0] * factor[0], n);
        }
        else printf("is not a D_num\n");
  	}
	return 0;
}
