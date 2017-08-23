n,d=map(int,raw_input().split())
a=map(int,raw_input().split())
tmp=0
ans=0
for i in a:
	sum=max(0,(tmp-i)/d+1)
	tmp=i+sum*d
	ans+=sum
print ans
