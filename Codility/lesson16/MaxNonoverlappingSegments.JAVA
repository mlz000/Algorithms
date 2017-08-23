import java.util.*;
class Solution {
    public int solution(int[] A, int[] B) {
        int n = A.length;
        int last = -1, ans = 0;
        for (int i = 0; i < n; ++i)
            if (last < 0 || A[i] > B[last]) {
                ++ans;
                last = i;
            }
        return ans;
    }
}
