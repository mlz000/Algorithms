#include<cstring>  //DP ���� f[i][j]��ʾ����ȡ��j����ʣ��i��������ֵ 
#include<cstdio>   //f[i][j]=max(f[i][j],sum[i]-f[i-k][k]) 1<=k<=j*2 3ά���У����غö� 
#include<iostream> //sum[i]Ϊʣ��Ӳ�Һ� 
#include<algorithm> //���� 
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
	 } //2*j��2*j-1������1~i������� 
	printf("%d\n",f[n][1]); 
	//system("pause");
    return 0;
}
