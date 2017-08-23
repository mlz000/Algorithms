#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1024; 
char s[N][N]; 
int main()
{
    int n,l; 
    int heap[N*2];
    while(scanf("%d%d",&n,&l)&&(n||l))
    {
        int i,j; 
        for(j=0;j<n;++j)
         scanf("%s",s[j]);
        int cost=0;
        for(i=0;i<l;++i)
        {
           for(j=0;j<n;++j) 
            heap[n+j]=1<<(s[j][i]-'A'); //第n+k个节点的字符，转为二进制 
           for(j=n-1;j>0;--j)
           {
              if(!(heap[j]= heap[j*2]&heap[j*2+1])) 
              {
               cost++; 
               heap[j]=heap[j*2]|heap[j*2+1];
              } 
           } 
           char c='A';
           while(heap[1]>>=1) ++c;
           printf("%c",c);
        }
       printf(" %d\n",cost); 
    } 
    //system("pause");
    return 0;
}
