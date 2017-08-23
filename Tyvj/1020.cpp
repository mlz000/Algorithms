#include<stdio.h>
int a(int x)
{
    int i;
    if (x<2)
     return 0;
     for (i=2;i<=x;)
        if (x%i==0) x=x/i;
        else i++;
     return i;
}
int b(int x[],int n)
{
    int i,s=0;
      for (i=1;i<n;i++)
        if (x[i]>x[s])
           s=i;
         return s;
}
int main()
{
     int n,i;
scanf ("%d",&n);
int a1[n],b1[n];
    for (i=0;i<n;i++)
        {
                 scanf ("%d",&a1[i]);
                 b1[i]=a(a1[i]);
        }
               i=b(b1,n); 
           printf ("%d",a1[i]);
while (1)
return 0;
} 
