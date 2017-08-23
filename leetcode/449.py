class Codec:
    def serialize(self, root):
        if root is None:    return ''
        def dfs(t):
            if t is None:
                nodes.append('#')
                return
            nodes.append(str(t.val))
            dfs(t.left)
            dfs(t.right)
        if root is None:    return ''
        nodes = []
        dfs(root)
        return ','.join(nodes)

    def deserialize(self, data):
        if len(data) == 0:  return None
        nodes = data.split(',')
        def dfs():
            if nodes[pos[0]] == '#':
                pos[0] += 1
                return None
            root = TreeNode(int(nodes[pos[0]]))
            pos[0] += 1
            root.left = dfs()
            root.right = dfs()
            return root
        pos = [0]
        return dfs()