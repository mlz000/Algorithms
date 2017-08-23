class Solution {
    public int solution(int[] A) {
        int n = A.length;
        int ans = 0;
        int p = 0;
        for (int i = n - 1; i >= 1; --i) {
            while ((long)A[i] + A[p] < 0 && p < i - 1) ++p;
            if ((p != i && (long)A[p] + A[i] == 0) || A[i] == A[i - 1]) ++ans;
        }
        return n - ans;
    }
}
