import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main{
		Map<BigInteger,BigInteger> map=new HashMap<BigInteger,BigInteger>();
		BigInteger x0=new BigInteger("0");
		BigInteger x1=new BigInteger("1");
		BigInteger x2=new BigInteger("2");
		BigInteger x4=new BigInteger("4");
		BigInteger x6=new BigInteger("6");
		BigInteger dfs(BigInteger x){
			if(map.get(x)!=null)	return (BigInteger)map.get(x);
			BigInteger a=dfs(x.divide(x2));
			BigInteger b=x.divide(x2);//	x/2
			BigInteger c=b.subtract(x1);//	x/2-1
			BigInteger ans;
			if(x.mod(x2).equals(x1)){
				ans=a.multiply(x4).add(x6.multiply(b));
			}
			else{
				BigInteger d=dfs(c);
				ans=a.add(d);
				ans=ans.add(b.multiply(x2));
				ans=ans.subtract(x2);
				ans=ans.multiply(x2);
			}
			map.put(x, ans);
			return ans;
		}
		public void work() {
	        map.put(BigInteger.valueOf(0),BigInteger.valueOf(0));  
	        map.put(BigInteger.valueOf(1),BigInteger.valueOf(0));  
	        map.put(BigInteger.valueOf(2),BigInteger.valueOf(0));  
	        map.put(BigInteger.valueOf(3),BigInteger.valueOf(6));
	        Scanner cin = new Scanner(System.in);
			while(cin.hasNext()){
				System.out.println(dfs(cin.nextBigInteger()));
			}
		}
		public static void main(String[] args){
			Main e=new Main();
			e.work();
		}
}
