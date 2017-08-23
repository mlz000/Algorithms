#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,ans,a[N],p[N],l[N];
long long s[N];
void up(int L,int R,int len){
	if(len<ans)	return ;
	if(l[R]<=L && s[R]-s[L-1]==(long long)(len+1)*len/2)	ans=len;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		l[i]=max(l[i-1],p[a[i]]+1);
		p[a[i]]=i;
	}
	l[n+1]=n+1;
	for(int i=1;i<=n;++i)
		if(a[i]==1){
			up(i,i,1);
			for(int j=i-1,mx=1;l[i]<=j;--j){
				mx=max(mx,a[j]);
				if(j+mx-1<=n)	up(j,j+mx-1,mx);
			}
			for(int j=i+1,mx=1;l[j]<=i;++j){
				mx=max(mx,a[j]);
				if(j-mx+1>=1)	up(j-mx+1,j,mx);
			}
		}
	printf("%d\n",ans);
	return 0;
}
