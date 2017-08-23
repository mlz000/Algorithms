mport java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int n = A.length;
        Arrays.sort(A);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i + 2;
            for (int j = i + 1; j < n; ++j) {
                for (k = Math.max(k, j + 1); k < n && A[i] + A[j] > A[k]; ++k);
                ans += k - j - 1;
            }
        }
        return ans;
    }
}
