mport java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int n = A.length;
        Arrays.sort(A);
        int ans = 2000000000;
        for (int i = 0, j = n - 1; i < n && j >= i;) {
            ans = Math.min(ans, Math.abs(A[i] + A[j]));
            if (Math.abs(A[i]) > Math.abs(A[j])) ++i;
            else --j;
        }   
        return ans;
    }
}
