class Solution(object):
    def majorityElement(self, a):
        now, cnt = a[0], 1
        for i in xrange(1, len(a)):
            if a[i] == now:
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    now, cnt = a[i], 1
        return now
        