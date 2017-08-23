#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005,M=30;
char ss[N];
int n,k,sz,ch[N][M],f[N];//1 always lose 2 always win 3 can win can lose
void insert(char *s){
	int u=0,l=strlen(s);
	for(int i=0;i<l;++i){
		int c=s[i]-'a';
		if(!ch[u][c])	ch[u][c]=sz++;
		u=ch[u][c];		
	}
}
int main(){
	sz=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%s",ss);
		insert(ss);
	}
	for(int i=sz-1;i>=0;--i){
		f[i]=0;
		bool flag=false;
		for(int j=0;j<26;++j){
			if(ch[i][j]){
				flag=true;
				f[i]|=f[ch[i][j]]^3;
			}
		}
		if(!flag)	f[i]=1;
	}
	if(f[0]==3)	puts("First");
	else if(f[0]<=1)	puts("Second");
	else if(k&1)	puts("First");
	else puts("Second");
	return 0;
}
