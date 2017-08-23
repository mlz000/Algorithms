class Solution(object):
    def fractionToDecimal(self, a, b):
        sign = '' if a * b >= 0 else '-'
        a, b = abs(a), abs(b)
        x, y = divmod(a, b)
        ans = sign + str(x)
        ans += '' if a == 0 or y == 0 else '.'
        now, mp = '', {}
        while y != 0:
            if y in mp:
                now = now[: mp[y]] + '(' + now[mp[y] :] + ')'
                break
            mp[y] = len(now)
            x, y = divmod(y * 10, b)
            now += str(x)
        return ans + now