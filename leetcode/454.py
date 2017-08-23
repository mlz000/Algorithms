class Solution(object):
    def fourSumCount(self, A, B, C, D):
        n1, n2, n3, n4 = len(A), len(B), len(C), len(D)
        sum1, sum2 = {}, {}
        for i in xrange(n1):
            for j in xrange(n2):
                sum1[A[i] + B[j]] = sum1.get(A[i] + B[j], 0) + 1
        for i in xrange(n3):
            for j in xrange(n4):
                sum2[C[i] + D[j]] = sum2.get(C[i] + D[j], 0) + 1
        ans = 0
        for x in sum1:
            if -x in sum2:
                ans += sum1[x] * sum2[-x]
        return ans