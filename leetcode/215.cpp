class Solution {
	public:
		int QuickSelect(vector<int> a, int b, int e, int k) {
			int i = b, j = e, mid = a[(i + j) >> 1];
			while (i <= j) {
				while (a[i] > mid)    ++i;
				while (a[j] < mid)    --j;
				if (i <= j){
					swap(a[i], a[j]);
					++i, --j;
				}
			}
			if (b < j && k <= j) return QuickSelect(a, b, j, k);
			if (i < e && k >= i) return QuickSelect(a, i, e, k);
			return a[k];
		}
		int findKthLargest(vector<int>& nums, int k) {
			return QuickSelect(nums, 0, nums.size() - 1, k - 1);
		}
};
