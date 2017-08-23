class Solution(object):
    def exclusiveTime(self, N, logs):
        ans = [0] * N
        s = []
        last = 0
        for log in logs:
            fn, typ, time = log.split(':')
            fn, time = int(fn), int(time)   
            if typ == 'start':
                if s:
                    ans[s[-1]] += time - last 
                s.append(fn)
                last = time
            else:
                ans[s.pop()] += time - last + 1
                last = time + 1
        return ans