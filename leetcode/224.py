class Solution(object):
    def calculate(self, s):
        ans, now, sign, st = 0, 0, 1, [(0, 1)]
        for i in s+"+":
            if i.isdigit():
                now = now * 10 + int(i)
            elif i in "+-":
                ans += now * sign * st[-1][1]
                now = 0
                if i == "+":    sign = 1
                else: sign = -1
            elif i == "(":
                st.append((now, sign * st[-1][1]));
                now, sign = 0, 1
            elif i == ")":
                ans += st[-1][1] * sign * now + st[-1][0]
                st.pop()
                now = 0
        return ans