#include<cstdio>//��ѧ���� ���ԭ���� b����Ϊ��ֵ����[l,r]��1�൱��b[l]+1,b[r+1]-1�����ǽ�����2���Ӽ�һ 
#include<iostream>//��b�������м���������Ӧ������Ϊmin(x,y)��ʣ��abs(x-y)������d1��Ӧ������3,3,3,3,6 
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

