#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[65],len,n;
bool used[65];//used为false时表示该木棍未用过 
bool dfs(int i,int l,int t)//第i个标号的木棍 剩下l长度拼成一个木棍 t初始为总长度 
{
      if(l==0)
      {
         t=t-len;
         if(t==0) return true;
         for(i=1;used[i];++i);
         used[i]=true;//当前最大值必然要取 
         if(dfs(i+1,len-a[i],t)) return true; 
         used[i]=false;
         t=t+len;
      }
      else
      {
            int j;
           for(j=i;j<=n;++j)
          {
             if(j>=2&&a[j]==a[j-1]&&(!used[j-1]))//2根都一样，前一个没用过后一个也不会用 
             continue;
             if( (!used[j])&&l>=a[j])//未访问过，且剩余长度大于此木棍长 
             {
                l=l-a[j];
                used[j]=true; 
                if(dfs(j,l,t)) return true;
                used[j]=false;
                l=l+a[j];
                if(a[j]==l) break;  //往下搜必然失败，返回上一层 
             }
          }
      }
      return false;
}
bool cmp(const int &b,const int &c)
{
      return b>c;
}
int main()
{
       while(scanf("%d",&n)&&n)
 {
        int i;
       int sum=0;
       for(i=1;i<=n;++i)
       {
         scanf("%d",&a[i]);
         sum+=a[i];
       }
       sort(&a[1],&a[n+1],cmp);
       bool flag=false;  
       for(len=a[1];len<=sum/2;++len)
       {
           if(sum%len==0)
           {
            if(dfs(1,len,sum)) {flag=true;printf("%d\n",len);break;}
           }
       }
        if(!flag) printf("%d\n",sum);
        memset(used,false,sizeof(used)); 
 } 
     system("pause");
     return 0; 
}
