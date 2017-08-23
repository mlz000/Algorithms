import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main{
	public static void main(String[] args) {
		Scanner read=new Scanner(System.in);
		while(read.hasNextInt()){
			int n=read.nextInt();
			int d=read.nextInt();
			BigInteger p,q;
			p=BigInteger.valueOf((d*d-d)/2).multiply(BigInteger.valueOf(n+4).pow(2));
		    q=BigInteger.valueOf(9).multiply(BigInteger.valueOf(n).pow(d));
			BigInteger a,b,t,z;
			z=BigInteger.valueOf(0);
			a=p;
			b=q;
			while(b.compareTo(z)!=0){
				t=a.remainder(b);
				a=b;
				b=t;
			}
			p=p.divide(a);
			q=q.divide(a);
			if(q.compareTo(BigInteger.valueOf(1))==0)	System.out.println(p.toString());
			else{
				System.out.print(p.toString());
				System.out.print("/");
				System.out.println(q.toString());
			}
		}
	}

}
