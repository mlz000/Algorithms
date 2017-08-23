n, d = map(int, raw_input().split())
if d == 0:
	print 1
else :
	f = [1]
	for i in range(0, d + 1):
		f.append(f[i] ** n + 1)
	print f[d] - f[d - 1]
