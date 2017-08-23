#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,N;
	cin >> N;
	n = N;
	if (n == 2)	cout << "3 4" << endl <<"5 2 3" << endl;
	else {
		cout << n;
		for(int i = 2; i < n; ++i)
			for(int j = n - i + 1; j < n; ++j)
				cout << " " << i * n + j + 1;
		cout << endl;
		n = (n % 2 ? n+2 : n+1);
		for(int i = N; i >= 1; --i) {
			cout << n;
			n += 2;
			for(int x = 0, y = i; x < N && y >= 0; ++x, --y) {
				if(y >= N)	continue;
				cout << " " << x * N + y + 1;
			}
			cout << endl;
		}
 	}
	return 0;
}
