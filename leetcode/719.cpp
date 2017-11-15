int cnt[1000005];
class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        int n = a.size();
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i)
            for (int j = i +1; j < n; ++j)
                cnt[abs(a[i] - a[j])]++;
        for (int i = 0; i <= 1000000; ++i) {
            if (cnt[i] >= k)    return i;
            k -= cnt[i];
        }
    }
};