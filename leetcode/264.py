class Solution(object):
    def nthUglyNumber(self, n):
        a = [0] * 1700; b = [2, 3, 5]; t = [0] * 3
        a[0] = 1; m = 1;
        while m < n:
            a[m] = min(a[t[0]] * 2, a[t[1]] * 3, a[t[2]] * 5)
            for i in range(3):
                if a[m] == a[t[i]] * b[i]:
                    t[i] += 1
            m += 1
        return a[n - 1]