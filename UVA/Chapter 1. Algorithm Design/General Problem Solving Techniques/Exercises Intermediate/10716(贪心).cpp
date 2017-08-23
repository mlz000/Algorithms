#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N=105;
char s[N];
int T,cnt[30];
int main(){
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		scanf("%s",s);
		memset(cnt,0,sizeof(cnt));
		int ans=0,tmp=0;
		int l=strlen(s);
		for(int i=0;i<l;++i)	cnt[s[i]-'a']++;
		for(int i=0;i<26;++i)	tmp+=cnt[i]%2;
		if(tmp>1)	{printf("Impossible\n");continue;}
		for(int i=0;i<(l+1)/2;++i){
			if(s[i]!=s[l-i-1]){
				int L=i,R=l-i-1;
				for(int j=L+1;j<R;++j){
					if(s[j]==s[R]){
						for(int k=j;k>i;--k)	swap(s[k],s[k-1]),ans++;
						break;
					}
					else if(s[l-j-1]==s[L]){
						for(int k=l-j-1;k<l-i-1;++k)	swap(s[k],s[k+1]),ans++;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


