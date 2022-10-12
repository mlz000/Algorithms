const int N = 1e5 + 5;
class Solution {
public:
    int mx[N << 2];
    int query(int rt, int l, int r, int L, int R) {
        int ans = 0;
        if (L > R) {
            return 0;
        }
        if (L <= l && R >= r) {
            return mx[rt];
        }
        int mid = (l + r) >> 1;
        if (L <= mid) {
            ans = max(ans, query(rt << 1, l, mid, L, R));
        }
        if (R > mid) {
            ans = max(ans, query(rt << 1 | 1, mid + 1, r, L, R));
        }
        return ans;
    }
    void update(int rt, int l, int r, int pos, int val) {
        if (l == r) {
            mx[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            update(rt << 1, l, mid, pos, val);
        } else {
            update(rt << 1 | 1, mid + 1, r, pos, val);
        }
        mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int ans = 0;
        int largest = *max_element(nums.begin(), nums.end());
        for (auto x : nums) {
            int t = query(1, 1, largest, max(x - k, 1), x - 1);
            update(1, 1, largest, x, t + 1);
        }
        return mx[1];
    }
};
