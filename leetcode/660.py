class Solution(object):
    def newInteger(self, n):
        a = []
        while n:
            a.append(n % 9)
            n /= 9
        return int("".join(map(str, a[::-1])))