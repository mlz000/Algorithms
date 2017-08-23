#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=1000005;
char s[N];
int cnt[15],sum[15],ans[N];
int main(){
	scanf("%s",s);
	int l=strlen(s);
	int tot=0;
	for(int i=0;i<l;++i)	cnt[s[i]-'0']++;
	cnt[1]--,cnt[6]--,cnt[8]--,cnt[9]--;
	for(int i=0;i<=9;++i) if(cnt[i]>0)	tot++;
	if(tot==1 && cnt[0])	{printf("1869");for(int i=1;i<=cnt[0];++i)	printf("0");}
	else{
		int now=0;
		for(int i=0;i<=9;++i)
			for(int j=1;j<=cnt[i];++j)
				ans[++now]=i;
		int mod=0;
		for(int i=now;i>=1;--i)
			mod=(mod*10+ans[i])%7;
		for(int i=now;i>=1;i--)	printf("%d",ans[i]);
		if(mod==0)	printf("1869");
		else if(mod==1)	printf("6891");
		else if(mod==2) printf("8196");
		else if(mod==3)	printf("1689");
		else if(mod==4)	printf("9861");
		else if(mod==5)	printf("1968");
		else if(mod==6)	printf("8691");
	}
	return 0;
}

