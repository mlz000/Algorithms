#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long NN;
const int N = 2e5 + 5;
const int M = 30;
string s, t;
string gao(string x) {
	if (x.size() & 1)	return x;
	string tmp = "";
	for (int i = 0; i < x.size() / 2; ++i)	tmp.pb(x[i]);
	string t1 = gao(tmp);
	tmp.clear();
	for (int i = x.size() / 2; i < x.size(); ++i)	tmp.pb(x[i]);
	string t2 = gao(tmp);
	if (t1 < t2)	return t1 + t2;
	else return t2 + t1;
}
int main() {
	cin >> s >> t;
	puts(gao(s) == gao(t) ? "YES" : "NO");
	return 0;
}
