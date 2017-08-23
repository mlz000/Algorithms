#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=50;
char s[N];
bool map[N][N],one;
int used[10];
int n;
void init()
{
     memset(map,false,sizeof(map));
     memset(used,false,sizeof(used));
     one=true;
     int i,j,l;
	 for(i=1;i<=n;++i)
     {
	   scanf("%s",s);
	   l=strlen(s);
	   for(j=2;j<l;++j,one=false)
	      map[i][s[j]-'A'+1]=true;
	 }
}
bool dfs(int num,int ans)
{
    int i,j;
	bool flag;
    for(i=1;i<=ans;++i)
    {
	   flag=true;
	   used[num]=i;
	   for(j=1;j<=n;++j)
	   {
	     if(map[num][j] && used[num]==used[j])
		 {
		   flag=false;
		   break;
		 } 
	   }
	   if(flag && (num==n || dfs(num+1,ans))) return true;
	}
	return false;
}
int main()
{
    while(scanf("%d",&n) &&n)
	{
	      init();
	   if(one) printf("1 channel needed.\n");
	   else if(dfs(1,2)) printf("2 channels needed.\n");
	   else if(dfs(1,3)) printf("3 channels needed.\n");
	   else printf("4 channels needed.\n");
	} 
    return 0;
}

