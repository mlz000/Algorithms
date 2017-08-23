#include<iostream>//SAM
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=250005<<1;
int last,tot,son[N][26],par[N],step[N],cnt[N],Q[N],g[N],f[N];
char s[N];
void ins(int x,int m){
	int p=last,np=++tot;
	step[np]=m,last=np,g[np]++;//right
	for(;!son[p][x] && p!=-1;p=par[p])	son[p][x]=np;
	if(p==-1)	return;
	else{
		int q=son[p][x];
		if(step[q]==step[p]+1)	par[np]=q;
		else{
			step[++tot]=step[p]+1;
			int nq=tot;
			memcpy(son[nq],son[q],sizeof(son[q]));
			par[nq]=par[q];
			par[q]=par[np]=nq;
			for(;son[p][x]==q && p!=-1;p=par[p])	son[p][x]=nq;	
		}
	}
}
int main(){
	par[0]=-1;
	scanf("%s",s);
	int l=strlen(s);
	for(int i=0;i<l;++i)	ins(s[i]-'a',i+1);
	for(int i=1;i<=tot;++i)	cnt[step[i]]++;
	for(int i=1;i<=tot;++i)	cnt[i]+=cnt[i-1];
	for(int i=1;i<=tot;++i)	Q[cnt[step[i]]--]=i;
	for(int i=tot;i>=1;--i)	f[step[Q[i]]]=max(f[step[Q[i]]],g[Q[i]]),g[par[Q[i]]]+=g[Q[i]];
	for(int i=1;i<=l;++i)	printf("%d\n",f[i]);
	return 0;
}
