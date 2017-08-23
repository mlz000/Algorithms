#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		double T1, T2, t1, t2;
		cin >> T1 >> T2 >> t1 >> t2;
		if (T1 > T2)	swap(T1, T2), swap(t1, t2);
		if (t2 >= T1)	t2 = T1;
		if (t1 >= T2)	t1 = T2;
		double ans = T1 * T2;
		if (t1 >= T2 - T1) {
			ans -= 0.5 * (T2 - t1) * (T2 - t1);	
			ans -= 0.5 * (T1 - t2) * (T1 - t2);			
		}
		else ans = 0.5 * (t1 + t1 + T1) * T1 - 0.5 * (T1 - t2) * (T1 - t2);	;
		printf("%.6lf\n", ans / (T1 * T2));
	}
	return 0;
}
