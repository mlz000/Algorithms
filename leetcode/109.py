class Solution(object):
    def sortedListToBST(self, head):
        if not head:
            return 
        if not head.next:
            return TreeNode(head.val)
        pre, mid, fast = ListNode(0), head, head
        while fast and fast.next:
            pre, mid = mid, mid.next
            fast = fast.next.next
        root = TreeNode(mid.val)
        pre.next = None
        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(mid.next)
        return root