#include<iostream>//��N*N�����ӷֳ�N*N/�࣬ÿ��4������Ϊת4�� 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=20;
int t,c[N][N],ans[N][N];
long long f[N*10]; 
bool v[N*10]; 
int n; 
long long calc()
{
  int i;
  long long ansc=1; 
  for(i=1;i<=t;++i)
  if(!v[i])  
  {
        if(ansc>2e18) break; 
        ansc=ansc*f[i]; 
  }
  return ansc; 
} 
int main()
{ 
    int i,j,k; 
    long long m; 
    scanf("%d%I64d",&n,&m);
    int x,y; 
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
     if(!c[i][j]) 
     {
        t++;
        f[t]=4;//��t����4��ȡ��
        for(k=1,x=i,y=j;k<=4;++k)
        {
         swap(x,y); x=n-x+1;c[x][y]=t;//4�������໥�ﵽ�ĸ��� 
        }
     } 
    m=(1ll<<2*t)-m+1;//��m�� 
    for(i=1;i<=n;++i)
     for(j=1;j<=n;++j)
     if(!v[c[i][j]]) //��c[i][j]��û�ù� 
     {
       v[c[i][j]]=1;
       long long tmp=calc(); //ʣ���
       if(tmp>=m) ans[i][j]=1;
       else 
       {
            m=m-tmp;
            v[c[i][j]]=0;
            f[c[i][j]]--; 
       } 
     } 
    for(i=1;i<=n;++i)
    {
      for(j=1;j<=n;++j)
       if(ans[i][j]) printf("1");
       else printf("0");
      printf("\n");  
     }
    //system("pause"); 
    return 0;
}

