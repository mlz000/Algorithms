int a[1001][1001], b[1001][1001];
class Solution {
public:

    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        int l = 0, r = min(na, nb);
        int ans = 0;
        for (int i = 0; i < na; ++i)
            for (int j = 0; j < nb; ++j) {
                if (min(na - i, nb - j) < ans)  break;
                int ti = i, tj = j, now = 0;
                while (ti < na && tj < nb && A[ti] == B[tj])    ++now, ++ti, ++tj;
                ans = max(ans, now);
            }
        return ans;
    }
};