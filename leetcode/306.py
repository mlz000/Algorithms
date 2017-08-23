class Solution(object):
    def isAdditiveNumber(self, num):
        n = len(num)
        for i in range(0, n):
            for j in range(i + 1, n - 1):
                a, b = num[ : i + 1], num[i + 1 : j + 1]
                if (len(a) > 1 and a[0] == '0') or (len(b) > 1 and b[0] == '0'):   continue
                while j < n:
                    c = str(int(a) + int(b))
                    #print(c, j)
                    if not num.startswith(c, j + 1):
                        break
                    j += len(c)
                    a, b = b, c
                if j == n - 1:  return True
        return False 