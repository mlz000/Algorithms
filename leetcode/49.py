class Solution(object):
    def groupAnagrams(self, strs):
        dic = {}
        for x in strs:
            s = ''.join(sorted(x))
            dic[s] = dic.get(s, []) + [x]
        return dic.values()