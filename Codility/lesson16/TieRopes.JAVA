import java.util.*;
class Solution {
    public int solution(int K, int[] A) {
         int n = A.length;
         int ans = 0;
         long sum = 0;
         for (int i = 0; i < n; ++i) {
            sum += A[i];
            if (sum >= K) {
                ++ans;
                sum = 0;
            }
         }
         return ans;
    }
}
