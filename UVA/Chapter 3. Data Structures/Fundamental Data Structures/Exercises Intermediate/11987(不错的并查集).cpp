#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int N=100005;
int ID,n,m,x,y,z,id[N],f[N],sum[N],tot[N];
int find(int x){
	if(f[x]!=x)	return f[x]=find(f[x]);
	return f[x];
}
void Union(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
	sum[y]+=sum[x];
	tot[y]+=tot[x];
}	
void creat(int x){
	int fx=find(id[x]);
	tot[fx]-=x,sum[fx]--;
	id[x]=++ID;
	sum[id[x]]=1,tot[id[x]]=x,f[id[x]]=id[x];
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		ID=n;
		for(int i=1;i<=n;++i)	f[i]=id[i]=tot[i]=i,sum[i]=1;
		while(m--){
			scanf("%d",&x);
			if(x==1){
				scanf("%d%d",&y,&z);
				if(find(id[y])!=find(id[z]))	Union(id[y],id[z]);
			}
			else if(x==2){
				scanf("%d%d",&y,&z);
				if(find(id[y])!=find(id[z])){
					creat(y);
					Union(id[y],id[z]);
				}
			}
			else{
				scanf("%d",&y);
				int fy=find(id[y]);
				printf("%d %d\n",sum[fy],tot[fy]);
			}
		}
	}
	return 0;
}
