import java.util.*;

class Solution {
    public int solution(int[] A) {
        int n = A.length;
        int sum = 0;
        int dp[] = new int[2000001];
        int cnt[] = new int[2000001];
        for (int i = 0; i < n; ++i) {
            A[i] = Math.abs(A[i]);
            sum += A[i];
            ++cnt[A[i]];
        }
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int i = 1; i <= 100; ++i)
            if (cnt[i] > 0){
                 for (int j = 0; j <= sum; ++j) {
                    if (dp[j] >= 0)  dp[j] = cnt[i];
                    else if (j >= i && dp[j - i] >= 0)    dp[j] = dp[j - i] - 1; 
                 }
            }
        int ans = 1000000000;
        for (int i = 0; i <= sum; ++i)
            if (dp[i] >= 0) ans = Math.min(ans, Math.abs(sum - i * 2));
        return ans;

    }
}
