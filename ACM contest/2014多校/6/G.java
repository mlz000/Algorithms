import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main{
        public static void main(String[] args){
            Scanner cin = new Scanner(System.in);
            int a[]=new int[3005];
            int T=cin.nextInt();
            for(int tt=1;tt<=T;++tt){
                int n;
                n=cin.nextInt();
                for(int i=0;i<n;++i)    a[i]=cin.nextInt();
                BigInteger ans=new BigInteger("0");
                BigInteger p=BigInteger.ONE;
                for(int i=0;i<n;++i){    
                    BigInteger tmp=BigInteger.ZERO;
                    tmp=p.multiply(BigInteger.valueOf(a[i]));
                    if(i%2==1){
                        tmp=BigInteger.ZERO.subtract(tmp);
                    }
                    ans=ans.add(tmp);
                    p=p.multiply(BigInteger.valueOf(n-i-1)).divide(BigInteger.valueOf(i+1));
                }
                if(n%2==0)    ans=BigInteger.ZERO.subtract(ans);
                System.out.println(ans);
            }
        }
}
