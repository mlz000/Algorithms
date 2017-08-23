#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
struct data{
	int step,pos;
};
int n,m;
int main(){
	while(scanf("%d%d",&n,&m)&&n&&m){
		if(n>=49 || m==1)	printf("Let me try!\n");
		else{
			bool flag=false;
			queue<data>Q;
			data tmp;
			tmp.step=1,tmp.pos=1;
			Q.push(tmp);
			while(Q.size()){
				data t=Q.front();
				Q.pop();
				data now;
				now.step=t.step+1;
				now.pos=t.pos+2*now.step-1;
				if(now.pos==m)	flag=true;
				if(now.pos>=1 && now.pos<=n)	Q.push(now);
				now.pos=t.pos-2*now.step+1;
				if(now.pos>=1 && now.pos<=n)	Q.push(now);
				if(now.pos==m)	flag=true;
			}
			if(flag)	printf("Let me try!\n");
			else printf("Don't make fun of me!\n");
		}
	}
	return 0;
}
