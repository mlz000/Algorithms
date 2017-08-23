class Solution(object):
    def findDuplicate(self, paths):
        M = collections.defaultdict(list)
        for line in paths:
            data = line.split()
            root = data[0]
            for file in data[1:]:
                name, _, content = file.partition('(')
                M[content[:-1]].append(root + '/' + name) 
        return [x for x in M.values() if len(x) > 1]