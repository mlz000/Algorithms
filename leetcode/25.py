class Solution(object):
    def reverseKGroup(self, head, k):
        if head is None or k < 2:   return head
        now = head
        for i in xrange(k - 1):
            now = now.next
            if now == None: return head
        pre, cur = None, head
        for i in xrange(k):
            pre, cur.next, cur = cur, pre, cur.next
        head.next = self.reverseKGroup(cur, k)
        return now