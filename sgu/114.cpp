#include <bits/stdc++.h>
using namespace std;
const int N = 15005;
typedef pair<double, int> pdi;
pdi a[N];
int main() {
	int n, y, sum = 0;
	cin >> n;
	double x;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		sum += y;
		a[i]=make_pair(x, y);
	}
	sort(a, a+n);
	sum = sum / 2 + 1;
	int now = 0;
	for (int i = 0; i < n; ++i) {
		now += a[i].second;
		if(now >= sum) {
			cout << a[i].first << endl; 
			break;
		}
	}
	return 0;
}
