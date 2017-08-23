#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 55;
int n, A[N], B[N];
//3: >=
//2: > 
//1: = 
//0: any
string f[N][N][N][4], inf;
struct LeftRightDigitsGame2 {
	string dp(int p, int l, int r, int fl) {
		string &tmp = f[p][l][r][fl];
		if (tmp != "!")	return tmp;
		tmp = "";
		string x = string(1, (char)(A[p] + '0'));
		if (l == r) {
			if (fl == 3 && A[p] >= B[l])	return tmp = x;
			if (fl == 2 && A[p] > B[l])		return tmp = x;
			if (fl == 1 && A[p] == B[l])	return tmp = x;
			if (fl == 0)	return tmp = x;
			return tmp = "";
		}
		string t1 = inf, t2 = inf, t;
		if (fl >= 2) {
			if (A[p] > B[l]) {
				t = dp(p - 1, l + 1, r, 0);
				if (t != "")	t1 = min(t1, x + t);//(l + 1, r)
			}
			else if (A[p] == B[l]) {
				t = dp(p - 1, l + 1, r, 2);
				if (t != "")	t1 = min(t1, x + t);
			}
			t = dp(p - 1, l, r - 1, 2); //(l, r - 1)
			if (t != "")	t2 = min(t2, t + x);
			if (A[p] > B[r]) {
				t = dp(p - 1, l, r - 1, 1);
				if (t != "")	t2 = min(t2, t + x);
			}
		}
		if (fl & 1) {
			if (A[p] == B[l]) {//(l + 1, r)
				t = dp(p - 1, l + 1, r, 1);
				if (t != "")	t1 = min(t1, x + t);					
			}
			if (A[p] == B[r]) {//(l, r - 1)
				t = dp(p - 1, l, r - 1, 1);
				if (t != "")	t2 = min(t2, t + x);
			}
		}
		if (!fl) {
			t = dp(p - 1, l + 1, r, 0);
			if (t != "")	t1 = min(t1, x + t);
			t = dp(p - 1, l, r - 1, 0);
			if (t != "")	t2 = min(t2, t + x);
		}
		tmp = min(t1, t2);
		if (tmp == inf)	tmp = "";
		return tmp;
	}
    string minNumber(string a, string b) {
    	int n = a.size();
		for (int i = 0; i < n; ++i) {
			inf += "9";
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					for (int l = 0; l < 4; ++l)
						f[i][j][k][l] = "!";
		}
		for (int i = 0; i < n; ++i)	A[i] = a[i] - '0', B[i] = b[i] - '0';
		string ans = dp(n - 1, 0, n - 1, 3);
    	if (ans == inf)	ans = "";
		return ans;
	}
};
