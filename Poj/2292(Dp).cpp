#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;
const int N = 35;
char s[]=" abcdefghijklmnopqrstuvwxyz+*/?";
int num[200], cnt[200], path[N][N], dp[N][N];
void init() {
	for (int i = 1; i <= 30; ++i)	num[s[i]] = i;
}
int main() {
	int T, n;
	scanf("%d", &T);
	init();
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		char ss[N];
		for (int i = 0; i < n; ++i) {
			scanf("%s", ss);
			for (int j = 0; ss[j]; ++j)	++cnt[num[ss[j]]];
		}
		for (int i = 1; i <= 12; ++i)	
			for (int j = 1; j <= 30; ++j)	
				dp[i][j] = INT_MAX / 100;
		int sum = 0;
		for (int j = 1; j <= 19; ++j) {
            sum += cnt[j] * j;
            dp[1][j] = sum;
            path[1][j] = 1;
        }
		for (int i = 2; i <= 12; ++i)
			for (int j = i; j <= 30; ++j) {
				for (int k = i; k <= j; ++k) {
					sum = 0;
					for (int l = k; l <= j; ++l)	sum += cnt[l] * (l - k + 1); 
					if (dp[i][j] > dp[i - 1][k - 1] + sum) {
						dp[i][j] = dp[i - 1][k - 1] + sum;
						path[i][j] = k;
					}
				}
			}
		vector<int> ans;
		int last = 30;
		for (int i = 12; i > 1; --i) {
			ans.push_back(path[i][last]);
			last = path[i][last] - 1;
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < 11; ++i)	printf("%c", s[ans[i]]);
		puts("");
	}
	return 0;
}
