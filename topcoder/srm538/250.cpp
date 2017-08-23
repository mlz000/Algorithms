#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
class EvenRoute {
        public:
        string isItPossible(vector <int> x, vector <int> y, int wantedParity) {
        	int n = x.size();
			bool even = 0, odd = 0;
			for (int i = 0; i < n; ++i) {
				if ((abs(x[i]) + abs(y[i])) & 1)	odd = 1;
				else even = 1;
			}
			return (odd && even) || (even && !wantedParity) || (odd && wantedParity) ? "CAN" : "CANNOT";
		}
};
