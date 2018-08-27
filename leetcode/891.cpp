const int M  = 1e9 + 7;
int p[20005];
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        p[0] = 1;
        for (int i = 1; i <= 20000; ++i)    p[i] = p[i - 1] * 2 % M;
        for (int i = 0; i < A.size(); ++i) {
            ans = (ans + (long long)p[i] * A[i] % M) % M;
            ans = (ans + M - (long long)p[A.size() - i - 1] * A[i] % M) % M;
        }
        return ans;
    }
};
