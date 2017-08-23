#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int N=20005;
int ca,ca2,p,q,v,k,x,n,Q,f[N],w[N];
char s1[20],s2[20];
bool know,bug;
int find(int x){
	if(f[x]!=x){
		int fx=find(f[x]);
		w[x]^=w[f[x]];
		f[x]=fx;
	}
	return f[x];
}
void Union(int x,int y,int v){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy){
		if((w[x]^w[y])!=v) bug=true;
		return;
	}
	if(fx==n)	swap(fx,fy);
	f[fx]=fy;
	w[fx]=w[x]^v^w[y];	//>_<
}
int main(){
	while(scanf("%d%d",&n,&Q)&&n+Q){
		++ca;
		ca2=0;
		bug=false;
		for(int i=0;i<=n;++i)	f[i]=i,w[i]=0;
		printf("Case %d:\n",ca);
		while(Q--){
			scanf("%s",s1);
			if(s1[0]=='I'){
				++ca2;
				gets(s1);
				if(bug)	continue;
				int cnt=sscanf(s1,"%d%d%d",&p,&q,&v);
				if(cnt==2)	v=q,q=n;
				Union(p,q,v);
				if(bug)	{printf("The first %d facts are conflicting.\n",ca2);continue;}
			}
			else{
				know=true;
				scanf("%d",&k);
				int ans=0;
				map<int,int>mp;
				while(k--){
					scanf("%d",&x);
					int fx=find(x);
					ans^=w[x];
					mp[fx]++;
				}
				if(bug)	continue;
				map<int,int>::iterator it;
				for(it=mp.begin();it!=mp.end();it++){
					if(it->second%2){
						if(it->first!=n)	{know=false;break;}
						else ans^=w[it->first];
					}
				}
				if(!know)	printf("I don't know.\n");
				else printf("%d\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}
