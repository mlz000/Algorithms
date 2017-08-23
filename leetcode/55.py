class Solution(object):
    def canJump(self, a):
        n, zero = len(a), []
        if n == 1:  return True
        for i in xrange(n - 1):
            if a[i] == 0:  zero.append(i)
        if len(zero) == 0:  return True
        now, i = 0, 0
        while i < n:
            if i < zero[now] and i + a[i] > zero[now]:
                now += 1
            else:   i += 1
            if now == len(zero):    return True
        return False