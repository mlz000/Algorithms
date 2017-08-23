#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		stack<int> S;
		queue<int> Q;
		priority_queue<int> PQ;
		int f[4];
		f[1]=f[2]=f[3]=1;
		for(int i=1,x,y;i<=n;++i){
			scanf("%d%d",&x,&y);
			if(x==1){
				Q.push(y);
				S.push(y);
				PQ.push(y);
			}
			else{
				int t;
				if(Q.empty())	f[1]=0;
				if(S.empty())	f[2]=0;
				if(PQ.empty())	f[3]=0;
				if(f[1]){
					t=Q.front();
					if(t!=y)	f[1]=0;
					Q.pop();
				}
				if(f[2]){
					t=S.top();
					if(t!=y)	f[2]=0;
					S.pop();
				}
				if(f[3]){
					t=PQ.top();
					if(t!=y)	f[3]=0;
					PQ.pop();
				}
			}
		}
		if(f[1]+f[2]+f[3]>=2)	printf("not sure\n");
		else if(f[1]+f[2]+f[3]==0)	printf("impossible\n");
		else if(f[1])	printf("queue\n");
		else if(f[2])	printf("stack\n");
		else printf("priority queue\n");
	}
	return 0;
}
