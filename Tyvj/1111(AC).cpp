#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=300;
int f[M];
bool p[M];
int find(int x)
{
    if(f[x]==x) return f[x];
    else return f[x]=find(f[x]);
}
int main()
{
      int i,j,n,cnt=0;
      int a,fa,fi;
      scanf("%d",&n);
      for(i=1;i<=n;++i)
      f[i]=i;
      for(i=1;i<=n;++i)
      {
	     while(scanf("%d",&a)&&(a!=0)) 
		 {
				fa=find(a);
		        fi=find(i);
		        if(fa!=fi) f[fa]=fi;
		 }
	  }
	  for(i=1;i<=n;++i)
	  {
		fi=find(i);
		if(!p[fi]) {cnt++;p[fi]=true;}
	  }
	  printf("%d",cnt);
	 // system("pause");
	  return 0;
}
