#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
class frac{
	public:
	int p, q;
	frac(int x, int y) {
		int t = __gcd(x, y);
		if (!t)	p = 0;
		else p = x / t, q =  y / t;
		if (q < 0)	p *= -1, q *= -1;
	}
	friend frac operator+ (const frac &a, const frac &b) {
		return frac(a.p * b.q + a.q * b.p, a.q * b.q);
	}
	friend frac operator- (const frac &a, const frac &b) {
		return frac(a.p * b.q - a.q * b.p, a.q * b.q);
	}
	friend frac operator* (const frac &a, const frac &b) {
		return frac(a.p * b.p, a.q * b.q);
	}
	friend frac operator/ (const frac &a, const frac &b) {
		return frac(a.p * b.q, a.q * b.p);
	}
	friend bool operator< (const frac &a, const frac &b) {
		return a.p * b.q < a.q * b.p;
	}
	friend bool operator> (const frac &a, const frac &b) {
		return b < a;
	}
	friend bool operator== (const frac &a, const frac &b) {
		return a.p * b.q == a.q * b.p;
	}	
	friend bool operator<= (const frac &a, const frac &b) {
		return a < b || a == b;
	}
	friend bool operator>= (const frac &a, const frac &b) {
		return !(a < b);
	}	
};
void print(frac z) {
	printf("%d", z.p);
	if (z.q > 1)	printf("/%d", z.q);
	printf(" ");
}
int main() {
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF) {
		frac x(a,b), y(c, d);
		print(x + y);
		print(x - y);
		print(x * y);
		print(x / y);
		printf("%s\n", x < y ? "true" : "false");
	}
	return 0;
}
