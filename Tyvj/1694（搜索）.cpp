#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct data
{
  int a[11][11];
}a;//将图横过来 
int n;
int num[11];
int ans[11][11];
data dfs1(data c)
{
     for(int i=1;i<=5;++i)
      for(int j=1;j<=7;++j)
	     if(c.a[i][j]==0)    //判断是否有为落下的块 
	     {
		   for(int k=j+1;k<=7;++k)
		    if(c.a[i][k]!=0)
			{
			  c.a[i][j]=c.a[i][k];
			  c.a[i][k]=0;
			  break;
			}	 
		 }
	 data d=c;bool flag=false;	 
     for(int i=1;i<=5;++i)
	  for(int j=1;j<=7;++j)
	   if(c.a[i][j]!=0)
	  {
	     int tot=1;
	     for(int k=j+1;k<=7;++k)
	      if(c.a[i][k]==c.a[i][k-1]) tot++;
	      else break;
	     if(tot>2)
	     {
		   d.a[i][j]=0;flag=true;
		   for(int k=j+1;k<=7;++k)
		    if(c.a[i][k]==c.a[i][k-1]) d.a[i][k]=0;
			else break; 
		 }
		 tot=1;
		for(int k=i+1;k<=5;++k)
		 if(c.a[k][j]==c.a[k-1][j]) tot++;
		 else break;
		if(tot>2)
		{
		  d.a[i][j]=0;flag=true;
		  for(int k=i+1;k<=5;++k)
		   if(c.a[k][j]==c.a[k-1][j]) d.a[k][j]=0;
		   else break;
		}  
	  }		 
      if(flag) d=dfs1(d);//dfs 
      if(flag) return d;
}
bool dfs(int t,data b)
{
      data e;
      memset(num,0,sizeof(num));
	  bool flag=true;b=dfs1(b);
      for(int i=1;i<=5;++i)
       for(int j=1;j<=7;++j)
        {
			if(b.a[i][j]>0) flag=false;//是否全部清除 
            num[b.a[i][j]]++;
		}
	  if(flag) return true;
	  if(t>n)  return false;
      for(int i=1;i<=10;++i) 
	   if(num[i]==1 || num[i]==2) return false;//只有1或2个必不成立
	  for(int i=1;i<=4;++i)
	   for(int j=1;j<=7;++j)
	    if((b.a[i][j]!=0 || b.a[i+1][j]!=0) && (b.a[i][j]!=b.a[i+1][j]))
		{
		  e=b;int k=b.a[i][j];
		  e.a[i][j]=b.a[i+1][j];
		  e.a[i+1][j]=k;
		  if(dfs(t+1,e))
		  {
		    ans[t][1]=i;ans[t][2]=j;ans[t][3]=1;//右移字典序小 
		    if(b.a[i][j]==0) {ans[t][1]=i+1;ans[t][2]=j;ans[t][3]=-1;}//左面无块只能左移； 
		    return true; 
		  }
		}  	    
    return false;		 
}
int main()
{
   int i,j;
   scanf("%d",&n);
   for(i=1;i<=5;++i)
    for(j=1;j<=8;++j)
     {
			scanf("%d",&a.a[i][j]);
			if(a.a[i][j]==0) break;
	 }
   if(dfs(1,a)) {for(i=1;i<=n;++i) printf("%d %d %d\n",ans[i][1]-1,ans[i][2]-1,ans[i][3]);}
   else printf("-1");
   return 0;
}

