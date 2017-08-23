class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        def work(nums, k):
            t, n = [] ,len(nums)
            for i in xrange(n):
                while t and len(t) + n - i > k and nums[i] > t[-1]:
                    t.pop()
                if len(t) < k:  t.append(nums[i])
            return t

        ans = [0] * k
        for i in xrange(max(0, k - len(nums2)), min(k, len(nums1)) + 1):
            t1 = work(nums1, i)
            t2 = work(nums2, k - i)
            ans = max(ans, [max(t1, t2).pop(0) for i in xrange(k)])
        return ans