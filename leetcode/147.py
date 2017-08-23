class Solution(object):
    def insertionSortList(self, head):
        dummy = now = ListNode(0)
        while head:
            if now and now.val > head.val:
                now = dummy
            while now.next and now.next.val < head.val:
                now = now.next
            now.next, now.next.next, head = head, now.next, head.next 
        return dummy.next