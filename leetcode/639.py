class Solution(object):
    def numDecodings(self, s):
        M = 10 ** 9 + 7
        f0, f1, f2 = 1, 0, 0
        for c in s:
            if c == '*':
                t0 = 9 * f0 + 9 * f1 + 6 * f2
                t1 = f0
                t2 = f0
            else:
                t0 = f0 * (1 if int(c) > 0 else 0) + f1 + f2 * (1 if int(c) <= 6 else 0)
                t1 = f0 * (1 if c == '1' else 0)
                t2 = f0 * (1 if c == '2' else 0)
            t0 %= M
            f0, f1, f2 = t0, t1, t2
        return f0