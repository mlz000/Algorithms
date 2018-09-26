class Solution {
public:
    bool dp[31][300001];
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        int sum = 0;
        for (auto x : A)    sum += x;
        for (int i = 1; i < n; ++i) {
            if (sum * i % n != 0)   continue;
            int now = sum * i / n;
            memset(dp, 0, sizeof(dp));
            dp[0][0] = true;
            for (int j = 0; j < n; ++j)
                for (int k = i; k >= 1; --k)
                    for (int l = 0; l <= now; ++l) {
                        if (dp[k - 1][l]) {
                            dp[k][l + A[j]] = true;
                        }
                    }
            if (dp[i][now]) return true;
        }
        return false;
    }
};