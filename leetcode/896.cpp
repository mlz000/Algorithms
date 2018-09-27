class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        vector<int> B = A;
        sort(B.begin(), B.end());
        bool ok = 1;
        for (int i = 0; i < A.size(); ++i) {
            ok &= A[i] == B[i];
        }
        if (ok) return true;
        ok = 1;
        reverse(B.begin(), B.end());
        for (int i = 0; i < A.size(); ++i) {
            ok &= A[i] == B[i];
        }
        return ok;
    }
};
