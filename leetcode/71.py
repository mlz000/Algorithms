class Solution(object):
    def simplifyPath(self, path):
        stack = []
        s = path.split('/')
        for p in s:
            if p == "..":
                if stack: stack.pop()
            elif p != '' and p != '.': stack.append(p)
        return '/' + '/'.join(stack)