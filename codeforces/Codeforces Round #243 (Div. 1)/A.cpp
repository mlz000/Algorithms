#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=205;
int a[N],b[N],c[N];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	int ans=-100000;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j){
			b[0]=c[0]=0;
			for(int k=1;k<=n;++k){
				if(k<i || k>j)	b[++b[0]]=a[k];
				else c[++c[0]]=a[k];
			}
			sort(b+1,b+b[0]+1);
			sort(c+1,c+c[0]+1);
			int p=min(b[0],min(c[0],m));
			for(int k=1;k<=p;++k)	if(c[k]<b[b[0]-k+1])	swap(c[k],b[b[0]-k+1]);
			int tmp=0;
			for(int k=1;k<=c[0];++k)	tmp+=c[k];
			ans=max(ans,tmp);
		}
	printf("%d\n",ans);
	return 0;
}
