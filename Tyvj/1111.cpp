#include<cstdio>
#include<iostream>
#include<algorithm>//堆栈溢出怎么回事 
using namespace std;
const int M=300;
int f[M],rank[M];
bool p[M];
int i;
void set(int n)
{
	for(i=1;i<=n;++i)
	{f[i]=i;rank[i]=0;}
}
int find(int x)
{
    if(f[x]==x) return f[x];
    else return f[x]=find(f[x]);
}
int main()
{
      int n,cnt=0;
      int a,fa,fi;
      scanf("%d",&n);
      set(n);
      for(i=1;i<=n;++i)
      {
	     while(scanf("%d",&a)&&(a!=0)) 
		 {
				fa=find(a);
		        fi=find(i);
		        if(rank[fa]>rank[fi]) f[fi]=fa;
		        else if(rank[fa]<rank[fi]) f[fa]=fi;
		        else { f[fi] = fa; rank[fa]++; }
		 }
	  }
	  for(i=1;i<=n;++i)
	  {
		fi=find(i);
		if(!p[fi]) {cnt++;p[fi]=true;}
	  }
	  printf("%d\n",cnt);
	  system("pause");
	  return 0;
}
