#include<cstdio>  //ֻ��Ҫ����1~N����Щ�����������������Ϳ����ˣ����ҽ���x=P div xʱ��Ҳ����P=x^2ʱ��P������������ 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath> 
using namespace std;
int main()
{
    int i,n,t; 
      scanf("%d",&t);
    for(i=1;i<=t;++i)
    {
        scanf("%d",&n);
        int x=sqrt(n);
        printf("%d\n",x);   
    }  
    return 0;
}
