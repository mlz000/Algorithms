#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n < 4)	puts("NO");
	else {
		puts("YES");
		if(n & 1) {
			cout << "5 * 4 = 20" << endl << "20 + 3 = 23" << endl
				 << "23 + 2 = 25" << endl << "25 - 1 = 24" <<endl; 
		}
		else {
			cout << "4 * 3 = 12" << endl << "12 * 2 = 24" << endl << "24 * 1 = 24" <<endl;
		}
		for (int i = 5 + (n & 1); i < n; i += 2) {
			cout << i + 1 << " - " << i <<" = 1" <<endl;
			cout << "24 * 1 = 24" << endl;
		}
	}
	return 0;
}
