class BSTIterator:
    def __init__(self, root):
        self.stack = list()
        self.pushAll(root)
    def hasNext(self):
        return self.stack
    def next(self):
        tmpNode = self.stack.pop()
        self.pushAll(tmpNode.right)
        return tmpNode.val     
    def pushAll(self, node):
        while node is not None:
            self.stack.append(node)
            node = node.left