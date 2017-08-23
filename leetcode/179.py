class Solution:
    def largestNumber(self, a):
        s = [str(i) for i in a]
        s.sort(lambda a, b : cmp(b + a, a + b))
        return ''.join(s).lstrip('0') or '0'