typedef long long LL;
class Solution {
public:
	int ans = 0, b[50005];
	void merge(vector<int> &a, int l, int m, int r) {
		int i = l, j = m + 1, k = l;
		while (i <= m && j <= r) {
			if (a[i] > (LL)a[j] * 2)	ans += m - i + 1, ++j;
			else ++i;
		}
		i = l, j = m + 1;
		while (i <= m && j <= r) {
			if (a[i] > a[j])	b[k++] = a[j++];
			else b[k++] = a[i++];
		}
		while (i <= m)	b[k++] = a[i++];
		while (j <= r)	b[k++] = a[j++];
		for (i = l; i <= r; ++i)	a[i] = b[i];
	}
	void ms(vector<int> &a, int l, int r) {
		if (l < r) {
			int m = l + r >> 1;
			ms(a, l, m), ms(a, m + 1, r);
			merge(a, l, m, r);
		}
	}
    int reversePairs(vector<int>& a) {
        int n = a.size();
		ms(a, 0, n - 1);
		return ans;
    }
};