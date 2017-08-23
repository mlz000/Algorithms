class Solution(object):
    def reverseBetween(self, head, m, n):
        dummy = pre = ListNode(0)
        dummy.next = head
        for i in xrange(m - 1):   pre = pre.next
        cur = pre.next
        node = None
        for i in xrange(n - m + 1):
            nxt = cur.next
            cur.next = node
            node = cur
            cur = nxt
        pre.next.next = cur
        pre.next = node
        return dummy.next