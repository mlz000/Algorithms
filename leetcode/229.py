class Solution(object):
    def majorityElement(self, a):
        n = len(a)
        if n == 0:  return []
        if n == 1:  return [a[0]]
        x, y, cnt0, cnt1 = 2 ** 32, 2 ** 32, 0, 0
        for i in a:
            if i == x:
                cnt0 += 1
            elif i == y:
                cnt1 += 1
            elif cnt0 == 0:
                x, cnt0 = i, 1
            elif cnt1 == 0:
                y, cnt1 = i, 1
            else:
                cnt0 -= 1
                cnt1 -= 1
        return [t for t in (x, y) if a.count(t) > len(a) // 3]