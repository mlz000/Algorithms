import random
class Solution(object):
    def __init__(self, head):
        self.a = []
        while head:
            self.a += head.val,
            head = head.next
    def getRandom(self):
        return self.a[random.randint(0, len(self.a) - 1)]