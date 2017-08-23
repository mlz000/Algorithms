class Solution(object):
    def superPow(self, a, bb):
       b = 0
       for x in bb: b = b * 10 + x
       ans = 1
       while b:
          if b & 1: ans = ans * a % 1337
          a = a * a % 1337
          b >>= 1
       return ans