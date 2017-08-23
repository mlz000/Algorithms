class Solution(object):
    def myAtoi(self, str):
        s = str.strip()
        s = re.findall('^[\+\-0]?\d+', s)
        try:
            ans = int(''.join(s))
            print(ans)
            mx = 2 ** 31 - 1
            mn = -2 ** 31
            if ans > mx:    return mx
            if ans < mn:    return mn
            return ans
        except:
            return 0