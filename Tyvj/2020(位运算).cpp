#include<cstdio> //λ������� 
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
    int last[2]={0,0};//��һ��0,1λ�� 
    int xo[2]={0,0}; //0,1���������� 
    for(i=1;i<=n;++i)
     b[i]=((a[i]>>w)&1); //��iλ
    for(i=1;i<=n;++i)
    {
      if(i!=1)
      {
         ansxor+=(double)(1<<w)/n/n*xo[!b[i]];//���ÿ������0���䣬����1ȡ��
         if(b[i]==0) ansor+=(double)(1<<w)/n/n*last[1];//���������1�Ժ���ԶΪ1
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
        ++xo[1];//�������1ȡ�� 
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
       solve(i);//��λ���  
      printf("%.3lf %.3lf %.3lf\n",ansxor*2,ansand*2,ansor*2); 
   //  system("pause");  
      return 0; 
} 

