#include<bits/stdc++.h>//76576500
using namespace std;
int main(){
    int count=1;
    int i=70;
    while(count<500){
		count = 1;
		int div = 2;
		int now = (i+1)*i/2;
	   	while (now > 1){
	    	int t = 0;
	    	while (now % div == 0){
				now /= div;
				t++;
	   		}
		   	count *= t+1;
	   	 	div++;
		}
		i++;
    }
    printf("%d",(i-1)*i/2);
	return 0;
}
