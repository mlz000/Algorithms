class Solution(object):
    def deserialize(self, s):
        def nestedInteger(x):
            if isinstance(x, int):
                return NestedInteger(x)
            lst = NestedInteger()
            for y in x:
                lst.add(nestedInteger(y))
            return lst
        return nestedInteger(eval(s))