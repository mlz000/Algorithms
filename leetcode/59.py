class Solution:
    def generateMatrix(self, n):
        if n == 0:
            return []  
        res = [[0] * n for x in range(n)]       
        num = 1      
        res[0][0] = 1
        for i in range((n + 1) / 2):
            for j in range(i, n - i):
                res[i][j] = num
                num += 1         
            for j in range(i + 1, n - i):
                res[j][n - i - 1] = num
                num += 1          
            for j in range(n - i - 2, i - 1, -1):
                res[n - i - 1][j] = num
                num += 1            
            for j in range(n - i - 2, i, -1):
                res[j][i] = num
                num += 1        
        return res