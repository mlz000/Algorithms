class Solution(object):
    def isValidSerialization(self, s):
        du = 1
        for t in s.split(','):
            du -= 1
            if du < 0:  return False
            if t != '#':    du += 2
        return du == 0