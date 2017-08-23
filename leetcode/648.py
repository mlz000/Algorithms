class Solution(object):
    def replaceWords(self, roots, sentence):
        def replace(word):
            for i in xrange(1, len(word)):
                if word[:i] in S:
                    return word[:i]
            return word
        S = set(roots)
        return " ".join(map(replace, sentence.split()))