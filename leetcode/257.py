class Solution(object):
    def binaryTreePaths(self, root):
        def dfs(rt, path):
            if (not rt.left) and (not rt.right):
                ans.append(path)
                return
            if rt.left:
                dfs(rt.left, path + [rt.left.val])
            if rt.right:
                dfs(rt.right, path + [rt.right.val])
        ans = []
        if not root:
            return []
        dfs(root, [root.val])
        return ["->".join(map(lambda x : str(x), t)) for t in ans]