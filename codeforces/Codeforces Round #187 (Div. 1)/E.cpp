#include <bits/stdc++.h>//dp
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
char s[N];
unsigned int f[2][N];
int main(){
	int n;
 	scanf("%d", &n);
    scanf("%s",s + 1);
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int now = i & 1;
		int x = min(i, n - i), y;
        if (!now) y = 2;
        else y = 1;
        if (s[i] == '?'){
            f[now][0] = f[now ^ 1][1];
            for (int j = y; j <= x; j += 2) f[now][j] = 25 * f[now ^ 1][j - 1] + f[now ^ 1][j + 1];
        }
        else {
            f[now][0] = 0;
            for (int j = y; j <= x; j += 2) f[now][j] = f[now ^ 1][j - 1];
        }
    }
    printf("%u",f[n & 1][0]);
    return 0;
}
