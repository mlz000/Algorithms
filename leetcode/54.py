class Solution(object):
    def spiralOrder(self, matrix):
        return matrix and list(matrix.pop(0)) + self.spiralOrder(zip(*matrix)[::-1])