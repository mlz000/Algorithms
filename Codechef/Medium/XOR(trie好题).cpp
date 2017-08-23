#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, a[N];
vector<int> ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)	scanf("%d", &a[i]);
	sort(a, a + n);
	int l = -1, r = 31;
	while (l < r - 1) {
		int mid = l + r >> 1;
		long long sum = 0ll;
		int i, j;
		for (i = j = 1; i < n; ++i) {
			if ((a[i] ^ a[i - 1]) < 1 << mid)	++j;//Êµ¼ÊÊÇtrie
			else sum += (long long)j * (j - 1) / 2, j = 1;
		}
		sum += (long long)j * (j - 1) / 2;
		if (sum >= k)	r = mid;
		else l = mid;
	}
	if (r == 0)	for (int i = 0; i < k; ++i)	printf("0 ");
	else {
		int i, j;
		for (i = 1, j = 0; i < n; ++i) {
			if ((a[i] ^ a[i - 1]) < 1 << r) 
				for (int l = j; l < i; ++l)	ans.push_back(a[i] ^ a[l]);
			else j = i;
		}
		partial_sort(ans.begin(), ans.begin() + k, ans.end());
		for (i = 0; i < k; ++i)	printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}
