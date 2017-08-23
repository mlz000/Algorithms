class Solution(object):
    def deleteDuplicates(self, head):
        dummy = ListNode(-10000)
        dummy.next, now = head, head
        pre = dummy
        last = -10000
        while now and now.next:
            if now.val == now.next.val:
                if now.next.next and now.next.next.val == now.val:
                    now.next = now.next.next
                else:
                    pre.next, now = now.next.next, now.next.next 
            else:  
                pre, now = now, now.next
        return dummy.next