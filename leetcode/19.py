class Solution(object):
    def removeNthFromEnd(self, head, n):
        l, now = 0, head
        while now:
            now = now.next
            l += 1
        l = l - n
        dummy = pre = ListNode(0)
        dummy.next, now = head, head
        while l > 0:
            pre, now = now, now.next
            l -= 1
        pre.next = (now.next or None)
        return dummy.next    