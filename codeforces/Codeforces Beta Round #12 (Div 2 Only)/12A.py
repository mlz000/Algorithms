s1=[raw_input() for x in range(0,3)]
s2=[x[::-1] for x in reversed(s1)]
print "YES" if s1==s2	else "NO"
