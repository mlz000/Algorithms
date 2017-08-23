class Solution:
    def postorderTraversal(self, root):
        stack, ans = [root], []
        while stack:
            rt = stack.pop()
            if rt:
                ans.append(rt.val)
                stack.append(rt.left)
                stack.append(rt.right)
        return ans[::-1]