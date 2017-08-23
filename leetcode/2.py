class Solution(object):
    def addTwoNumbers(self, l1, l2):
        root, now = ListNode(0), 0
        t = root
        while l1 or l2 or now:
            x = y = 0
            if l1:
                x, l1 = l1.val, l1.next
            if l2:
                y, l2 = l2.val, l2.next
            now, x = divmod(x + y + now, 10)
            t.next = ListNode(x)
            t = t.next
        return root.next    