//http://wenku.baidu.com/view/e918218dcc22bcd126ff0cf1.html
//Nimm Game 
//将每个数改成2^n次幂的形式  每个的个数和均为偶数时(可转化为两堆相同的)先手必败 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
      int i,j,n,a;
	  while(scanf("%d",&n)!=EOF)
	  {
		 int ans;
		 scanf("%d",&ans);	
         for(i=1;i<n;++i)
         {
			 scanf("%d",&a);
	         ans^=a;
		 }
		 if(ans!=0) printf("Yes\n");
		 else printf("No\n"); 
	  }       
          //system("pause");
		  return 0;    
} 
