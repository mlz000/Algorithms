#include <bits/stdc++.h>
using namespace std;
#define sz(x)	x.size() 
string S;
int pos;
class CircuitsConstruction {
    public:
		int solve(int x) {
			if (S[x] == 'X')	return 1;
			int a = solve(++pos);
			int b = solve(++pos);
			return (S[x] == 'A') ? a + b : max(a, b); 
		}
		int maximizeResistance(string s, vector <int> a) {
			S = s;
			sort(a.begin(), a.end());
			reverse(a.begin(), a.end());
			int p = solve(0);
			int ans = 0;
			for (int i = 0; i < p; ++i) ans += a[i];	 
			return ans;
		}
};
