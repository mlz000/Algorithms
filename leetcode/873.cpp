class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_set<int> s;
        for (auto x: A) s.insert(x);
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int x = A[i], y = A[j];
                if (!s.count(x + y))   continue;
                int now = 3;
                x += y;
                swap(x, y);
                while (s.count(x + y)) {
                    ++now;
                    x += y;
                    swap(x, y);
                }
                ans = max(ans, now);
            }
        return ans;
    }
};
