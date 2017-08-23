class Solution(object):
    def reverseVowels(self, s):
        s = list(s)
        t = []
        dict = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
        for c in s:
            if c in dict:
                t += c
        t = t[::-1]
        now = 0
        for i in xrange(len(s)):
            if s[i] in dict:
               s[i] = t[now]
               now += 1
        return "".join(s)