const int N = 1e4 + 5;
class Solution {
public:
	double get(int a[], int n1, int b[], int n2, int k) {
		if (n1 == 0)	return b[k - 1];
		if (n2 == 0)	return a[k - 1];
		if (k == 1)	return min(a[0], b[0]);
		int i = min(n1, k / 2), j = min(n2, k / 2);
		if (a[i - 1] > b[j - 1])	return get(a, n1, b + j, n2 - j, k - j);
		else return get(a + i, n1 - i, b, n2, k - i);
	}
    double findMedianSortedArrays(vector<int>& aa, vector<int>& bb) {
        int n1 = aa.size(), n2 = bb.size();
		int a[N], b[N];
		for (int i = 0; i < n1; ++i)	a[i] = aa[i];
		for (int i = 0; i < n2; ++i)	b[i] = bb[i];
		int m1 = (n1 + n2 + 1) >> 1, m2 = (n1 + n2 + 2) >> 1;
		return (get(a, n1, b, n2, m1) + get(a, n1, b, n2, m2)) / 2;	 
    }
};
