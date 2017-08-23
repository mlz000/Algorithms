#include<cstdio>//数学好题 差分原数列 b数列为差值。将[l,r]加1相当于b[l]+1,b[r+1]-1，就是讲任意2数加减一 
#include<iostream>//找b数列中有几正几负对应，操作为min(x,y)，剩余abs(x-y)个数和d1对应操作如3,3,3,3,6 
#include<algorithm>
#include<cmath> 
#include<cstring>
using namespace std;
const int N=100005;
long long a[N],b[N];
int main()
{
    int i,n;
    scanf("%d",&n);
  	for(i=1;i<=n;++i)
	 scanf("%lld",&a[i]);
	long long  x=0,y=0;
	for(i=1;i<n;++i)
	{
	  b[i]=a[i+1]-a[i];
	  if(b[i]>0) x+=b[i];
	  else y-=b[i];
	}  
	cout<<max(x,y)<<endl<<abs(x-y)+1;
//	system("pause");
    return 0;
}

