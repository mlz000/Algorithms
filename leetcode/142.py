class Solution(object):
    def detectCycle(self, head):
        s, f, ok = head, head, False
        while f and f.next:
            s = s.next
            f = f.next.next
            if s == f:
                ok = True
                break
        if not ok:  return None
        else:
            l, r = head, s
            while l != r:
                l, r = l.next, r.next
            return l