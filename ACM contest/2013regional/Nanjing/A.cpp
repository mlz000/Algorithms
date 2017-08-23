#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		double ans=0.0;
		int tot=0;
		while(n--){
			int x;
			char s[5];
			memset(s,0,sizeof(s));
			scanf("%d %s",&x,s);
			if(s[0]=='P' || s[0]=='N')	continue;
			else if(s[0]=='A'){
				if(s[1]=='-')	ans+=x*3.7;
				else ans+=x*4;
			}
			else if(s[0]=='B'){
				if(s[1]=='-')	ans+=x*2.7;
				else if(s[1]=='+')	ans+=x*3.3;
				else ans+=x*3.0;
			}
			else if(s[0]=='C'){
				if(s[1]=='+')	ans+=x*2.3;
				else if(s[1]=='-')	ans+=x*1.7;
				else ans+=x*2.0;
			}
			else if(s[0]=='D'){
				if(s[1]=='-')	ans+=x*1.0;
				else ans+=x*1.3;
			}
			tot+=x;
		}
		if(tot==0)	printf("0.00\n");
		else printf("%.2lf\n",ans/tot);
	}
	return 0;
}
