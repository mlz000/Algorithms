#include <cstdio>
#include <cstring> 
#include <iostream>
#include <algorithm>
#define MAX (1<<11)+1
using namespace std;
int w;
long long  a[2][MAX];
int t;
void dfs(int num,int now,int ago)
{
     if(num==w) {a[t][now]+=a[(t+1)%2][ago];return;}
     if(num+1<=w) 
     {
	      dfs(num+1,now<<1,(ago<<1)|1); //��ǰ�в�����
		  dfs(num+1,(now<<1)|1,ago<<1); //��ǰ������ 
	 }
	 if(num+2<=w) dfs(num+2,(now<<2)|3,(ago<<2)|3);//��ǰ��ˮƽ���� 
}
int main()
{
	 int i,h;
     while(scanf("%d%d",&h,&w)&&h&&w)
  {
	 if(h==0||w==0||(h*w)%2==1) {printf("0\n");continue;}	
     if(h<w) swap(h,w);
     t=0;
     a[t][(1<<w)-1]=1;//��0��������1��
	 for(i=1;i<=h;++i)
	 {
	   t=(t+1)%2;		
	   dfs(0,0,0);
	   memset(a[(t+1)%2],0,sizeof(a[0])); 
	 } 
     printf("%I64d\n",a[t][(1<<w)-1]); 
	 memset(a,0,sizeof(a));
  }
     //system("pause");
     return 0;
}
