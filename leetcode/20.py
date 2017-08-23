class Solution:
    def isValid(self, s):
        stack = []
        dict = {"]":"[", "}":"{", ")":"("}
        for c in s:
            if c in dict.values():
                stack.append(c)
            elif c in dict:
                if stack == [] or dict[c] != stack.pop():
                    return False
            else:
                return False
        return stack == []