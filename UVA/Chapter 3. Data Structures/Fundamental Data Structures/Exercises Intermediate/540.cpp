#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
const int N=1005;
int ca,t,m,x,next[N];
map<int,int>mp;
char s[20];
int main(){
	while(scanf("%d",&t)&&t){
		ca++;
		printf("Scenario #%d\n",ca);
		mp.clear();
		memset(next,0,sizeof(next));
		queue<int> q[N];
		for(int i=1;i<=t;++i){
			scanf("%d",&m);
			while(m--){
				scanf("%d",&x);
				mp[x]=i;
			}
		}
		int h=0,r=0;
		while(scanf("%s",s)&&s[0]!='S'){
			if(s[0]=='E'){
				scanf("%d",&x);
				if(!h)	h=r=mp[x],q[h].push(x);
				else{
					if(q[mp[x]].empty())	next[r]=mp[x],r=mp[x];
					q[mp[x]].push(x);
				}
			}
			else{
				int tmp=q[h].front();
				q[h].pop();
				if(q[h].empty())	h=next[h];
				printf("%d\n",tmp);
			}
		}
		printf("\n");
	}
	return 0;
}
				

