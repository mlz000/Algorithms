class Solution(object):
    def removeInvalidParentheses(self, s):
        def isvalid(s):
            cnt = 0
            for c in s:
                if c == '(':
                    cnt += 1
                elif c == ')':
                    cnt -= 1
                    if cnt < 0: return False
            return cnt == 0
        list = {s}
        now = 0
        while True:
            valid = filter(isvalid, list)
            now += 1
            if valid:   return valid
            list = {s[ : i] + s[i + 1 : ] for s in list for i in range(len(s))}