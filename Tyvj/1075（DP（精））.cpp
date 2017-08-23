#include<cstring>  //DP 倒推 f[i][j]表示对手取了j个还剩下i个的最优值 
#include<cstdio>   //f[i][j]=max(f[i][j],sum[i]-f[i-k][k]) 1<=k<=j*2 3维不行，算重好多 
#include<iostream> //sum[i]为剩余硬币和 
#include<algorithm> //好题 
using namespace std;
const int N=2005;
int a[N],sum[N]; 
int f[N][N]; 
int main()
{
    int i,j,n;
	scanf("%d",&n);
	for(i=n;i>=1;--i)
	 scanf("%d",&a[i]); 
    for(i=1;i<=n;++i)
	 sum[i]=sum[i-1]+a[i]; 
	for(i=1;i<=n;++i)
	 for(j=1;j<=n;++j)
	 {
	    f[i][j]=f[i][j-1];
		if(i-j*2+1>=0) f[i][j]=max(f[i][j],sum[i]-f[i-j*2+1][2*j-1]); //take 2*j-1
		if(i-j*2>=0)  f[i][j]=max(f[i][j],sum[i]-f[i-j*2][2*j]);//take 2*j 
	 } //2*j和2*j-1包括了1~i所有情况 
	printf("%d\n",f[n][1]); 
	//system("pause");
    return 0;
}
