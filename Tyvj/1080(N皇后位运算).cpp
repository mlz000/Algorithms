#include<cstdio>
#include<climits> 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=15; 
int full,ans,cnt,i,n; 
int path[N];
bool row[N],l[N*2],r[N*2]; 
void dfs(int a,int ld,int rd)
{
      if(a==full)
	  {
	    ans++;
		return ; 
	  } 
	  int can=~(a|ld|rd)&full,p;//可以放得位置
	  while(can!=0)
	  {
	    p=can&(~can+1);//取右数第一个1 
		can=can-p;
		dfs(a+p,(ld+p)<<1,(rd+p)>>1); 
	  } 
} 
int f1(int p,int q)
{
   return (p+q-1); 
} 
int f2(int p,int q)
{
   return (p-q+n); 
} 
void dfs3(int step)
{
   if(step>n)
    {
	  cnt++;
	  if(cnt>3) return; 
	     for(int i=1;i<=n;i++)
		  printf("%d ",path[i]);
		 printf("\n");  
	  return ; 
	} 
	for(int i=1;i<=n;i++)
	  if(!row[i] && !l[f1(step,i)] && !r[f2(step,i)])
	  {
	    row[i]=l[f1(step,i)]=r[f2(step,i)]=true;
	    path[step]=i; 
		dfs3(step+1);
		row[i]=l[f1(step,i)]=r[f2(step,i)]=false;
		if(cnt>3) return; 
	  } 
} 
int main()
{
	scanf("%d",&n); 
	full=(1<<n)-1; 
	dfs(0,0,0); 
	dfs3(1); 
	printf("%d\n",ans); 
//	 system("pause");
	 return 0; 
} 
