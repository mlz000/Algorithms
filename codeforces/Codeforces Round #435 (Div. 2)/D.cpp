#include <bits/stdc++.h>
using namespace std;
int ans[2], n;
int gao(int x) {
	string s(n, '0');
	for (int i = 0; i < x; ++i)	s[i] = '1';
	cout << "?" << " " << s << endl;
	fflush(stdout);
	int t;
	cin >> t;
	return n - t; // |same|
}
int main() {
	cin >> n;
	int t = gao(0), f;
	ans[f = t < gao(1)] = 1;
	int l = 2, r = n;
	while (l <= r) {
		int m = l + r >> 1;
		if (abs(gao(m) - t) == m)	l = m + 1;
		else ans[f ^ 1] = m, r = m - 1;
	}
	cout << "!" << " " << ans[0] << " " << ans[1] << endl;
	return 0;
}

