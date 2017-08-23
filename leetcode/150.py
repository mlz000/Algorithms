class Solution(object):
    def evalRPN(self, s):
        stack = []
        for c in s:
            if c not in ["+", "-", "*", "/"]:   stack.append(int(c))
            else:
                y, x = stack.pop(), stack.pop()
                if c == "+":    stack.append(x + y)
                elif c == "-":  stack.append(x - y)
                elif c == "*":  stack.append(x * y)
                else:
                    if x * y < 0 and x % y != 0:  stack.append(x / y + 1)
                    else:   stack.append(x / y)
        return stack.pop()