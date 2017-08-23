#include<cstdio> 
#include<climits> 
#include<iostream>
#include<string> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=15;
int a[N],b[N];
bool c[N];
int n,k;
long long ans;
void dfs(int x)
{
   if(x>n) {ans++;return;}
   for(int i=1;i<=n;++i)
    {
	   if((x!=n && !c[i] && abs(a[i]-b[x-1])<=k )||(x==n && !c[i] && abs(a[i]-b[x-1])<=k)&&abs(a[i]-b[1])<=k)
	   {
		  b[x]=a[i];
	      c[i]=true;
	      dfs(x+1);
	      b[x]=0;
	      c[i]=false;//回溯 
	   }
	} 
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)
	 scanf("%d",&a[i]);
	b[1]=a[1];
	c[1]=true;
	dfs(2);//固定第一个人 
	cout<<ans<<endl;
    //system("pause");
	return 0; 
}
