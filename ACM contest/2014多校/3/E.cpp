#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
char s[10000000];
int main(){
	int n;
	while(~(scanf("%d",&n))){
		char ch=getchar();
		int l=0;
		for(int i=1;i<=n;++i){
			ch=getchar();
			while(ch!='\n'){
				s[l++]=ch;
				ch=getchar();
			}
		}
		long long ans=1ll;
		int f=0,cnt=0;
		for(int i=0;i<l;){
			if(s[i]=='{'){
				while(s[i]!='}'){
					++i;
					if(s[i]=='|')	cnt++;
				}
			}
			ans=ans*(cnt+1);
			if(ans>100000 || f)	{f=1;break;}
			cnt=0;
			if(s[i]=='$'){
				++i;
				while(s[i]!='$'){
					if(s[i]!=' '){
						ans=ans*(cnt+1);
						if(ans>100000)	{f=1;break;}
						cnt=0;
					}
					else cnt++;
					++i;
				}
				ans=ans*(cnt+1);
			}
			++i;
			cnt=0;
			if(ans>100000 || f)	{f=1;break;}
		}
		if(f)	printf("doge\n");
		else printf("%I64d\n",ans);
	}
	return 0;
}

