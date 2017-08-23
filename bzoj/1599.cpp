#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int num[100];
int main()
{
   int s1,s2,s3,i,j,k;
   int MIN=-1;
   scanf("%d%d%d",&s1,&s2,&s3);
   for(i=1;i<=s1;++i)
     for(j=1;j<=s2;++j)
       for(k=1;k<=s3;++k)
          num[i+j+k]++;
        for(i=1;i<=s1+s2+s3;++i)
         if(num[i]>MIN) {k=i;MIN=num[i];}
      printf("%d",k);
      return 0;
}
