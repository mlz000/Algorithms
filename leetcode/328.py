class Solution(object):
    def oddEvenList(self, head):
        dummy1 = odd = ListNode(0)
        dummy2 = even = ListNode(0)
        while head:
            odd.next, even.next = head, head.next
            odd, even = odd.next, even.next
            head = head.next.next if even else None
        odd.next = dummy2.next
        return dummy1.next