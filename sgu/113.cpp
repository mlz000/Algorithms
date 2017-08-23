#include <bits/stdc++.h>
using namespace std;
int n, a;
bool ok;
bool prime(int x) {
	for (int i = 2; i * i <= x;i++) 
		if (x % i == 0) return false;
	return true;
}
int main() {
	cin >> n;
	while (n--) {
		cin >> a;
		ok = false;
		for (int i = 2; i * i <= a; ++i)
			if (a % i == 0) {
				if (prime(a / i)) {
					ok = true;
					break;
				}
				else break;
			}
		if (ok) cout << "Yes" << endl;
		else cout <<"No"<< endl;
	}
	return 0;
}
