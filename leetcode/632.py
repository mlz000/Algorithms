class Solution(object):
    def smallestRange(self, A):
        pq = [(a[0], i, 0) for i, a in enumerate(A)]
        heapq.heapify(pq)  
        ans = [-1e9, 1e9]
        right = max(a[0] for a in A)
        while pq:
            left, i, j = heapq.heappop(pq)
            if right - left < ans[1] - ans[0]:
                ans = [left, right]
            if j + 1 == len(A[i]):
                return ans
            v = A[i][j + 1]
            right = max(right, v)
            heapq.heappush(pq, (v, i, j + 1))