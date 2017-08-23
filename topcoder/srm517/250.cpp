#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int tot, p[N];
bool check[N];
class CompositeSmash {
	public:
	string thePossible(int N, int target) {
	 	if (N == target)	return "Yes";
		if (N % target)	return "No";
		for (int i = 2; i < target; ++i) {
			if (N % i == 0)	{
				if (thePossible(N / i, target)[0] == 'N')	return "No";
			}
		}
		return "Yes";
	}
};
