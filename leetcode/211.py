class WordDictionary(object):
    def __init__(self):
        self.G = collections.defaultdict(list)
    def addWord(self, word):
        if word:
            self.G[len(word)].append(word)
    def search(self, word):
        l = len(word)
        if not word:    return False
        if '.' not in word: return word in self.G[l]
        for s in self.G[l]:
            ok = True
            for i in xrange(0, l):
                if word[i] != s[i] and word[i] != '.':
                    ok = False
                    break
            if ok:  return True
        return False