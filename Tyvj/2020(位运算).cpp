#include<cstdio> //位运算好题 
#include<iostream>
#include<algorithm> 
using namespace std; 
const int N=1000005;
int a[N],b[N]; 
int n; 
double ansxor,ansand,ansor; 
void solve(int w)
{
    int i; 
    int last[2]={0,0};//上一个0,1位置 
    int xo[2]={0,0}; //0,1个数算异或和 
    for(i=1;i<=n;++i)
     b[i]=((a[i]>>w)&1); //第i位
    for(i=1;i<=n;++i)
    {
      if(i!=1)
      {
         ansxor+=(double)(1<<w)/n/n*xo[!b[i]];//异或每次碰到0不变，碰到1取反
         if(b[i]==0) ansor+=(double)(1<<w)/n/n*last[1];//或操作碰到1以后永远为1
         else if(b[i]==1)
         {
            ansand+=(double)(1<<w)/n/n*(i-last[0]-1);
            ansor+=(double)(1<<w)/n/n*(i-1); 
         } 
      } 
      last[b[i]]=i;
      if(b[i]==0) xo[0]++;
      else 
      {
        swap(xo[0],xo[1]);
        ++xo[1];//异或碰到1取反 
      } 
    } 
      for(i=1;i<=n;++i)
      if(b[i]) 
      {
        ansand+=(double)(1<<w)/n/n/2;
        ansxor+=(double)(1<<w)/n/n/2;
        ansor+=(double)(1<<w)/n/n/2;
      }  
} 
int main()
{ 
      int i; 
      scanf("%d",&n);
      for(i=1;i<=n;++i)
       scanf("%d",&a[i]);
      for(i=0;i<31;++i)
       solve(i);//逐位解决  
      printf("%.3lf %.3lf %.3lf\n",ansxor*2,ansand*2,ansor*2); 
   //  system("pause");  
      return 0; 
} 

