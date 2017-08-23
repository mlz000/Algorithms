#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair
#define F first
#define S second
inline void read(int &t) {
    int f = 1;char c;
    while (c = getchar(), c < '0' || c > '9') if (c == '-') f = -1;
    t = c - '0';
    while (c = getchar(), c >= '0' && c <= '9') t = t * 10 + c - '0';
    t *= f;
}
const int N = 10005;
int n;
string s[N];
bool cmp(const string a, const string b) {
	return a.length() != b.length() ? a.length() < b.length() : a < b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)	cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n; ++i)	cout << s[i] << endl;
	return 0;
}
