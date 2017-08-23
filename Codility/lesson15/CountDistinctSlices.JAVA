import java.util.*;

class Solution {
    public int solution(int M, int[] A) {
        int inf = 1000000000;
        int n = A.length;
        int last[] = new int[M + 1];
        Arrays.fill(last, -1);
        long ans = 0;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (last[A[i]] != -1) p = Math.max(p, last[A[i]] + 1); 
            last[A[i]] = i;
            ans += i - p + 1;
        }
        return (int)Math.min(ans, 1000000000L);
    }
}
