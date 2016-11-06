import java.math.*;
import java.io.*;
import java.util.*;
import static java.lang.System.out;
//https://www.acmicpc.net/problem/1010
public class Main{
    public static void main(String[] argv){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int count = in.nextInt();
        for(int i=0; i<count; i++){
            int r = in.nextInt();
            int n = in.nextInt();
            out.println(combination(r,n));
        }
        
    }
    private static class Fraction{
        public int n;
        public int d;
        private static int gcd(int a, int b){
            if(a<0 || b<0)
                throw new RuntimeException("can not calculate gcd from zero");
            while(a!=b){
                if(a>b)
                    a=a-b;
                else
                    b=b-a;
            }
            return a;
        }
        //side effect
        public void reduce(){
            int gcd = Fraction.gcd(n,d);
            n = n/gcd;
            d = d/gcd;
        }
        
        //side effect
        public static void reduce(Fraction f1, Fraction f2){
            int gcd = Fraction.gcd(f1.n,f2.d);
            f1.n = f1.n/gcd;
            f2.d = f2.d/gcd;
            gcd = Fraction.gcd(f1.d,f2.n);
            f1.d = f1.d/gcd;
            f2.n = f2.n/gcd;
        }

    }
    
    private static long combination(int r, int n){
        if(r==0 || r==n)
            return 1;
        Fraction[] arr = new Fraction[r];
        for(int i=0; i<r; i++){
            Fraction f = new Fraction();
            f.n = n-i;
            f.d = r-i;
            arr[i] = f;
        }
        /*for(int i=0; i<arr.length; i++){
            arr[i].reduce();
        }*/
        for(int i=0; i<arr.length; i++){
            for(int k=0; k<arr.length; k++){
                if(k != i){
                    Fraction.reduce(arr[i], arr[k]);
                }
            }
        }
        long resultN=1;
        long resultD=1;
        for(int i=0; i<arr.length; i++){
            resultN *= (long)arr[i].n;
            resultD *= (long)arr[i].d;
        }
        //out.println("N:"+resultN);
        //out.println("D:"+resultD);
        return resultN/resultD;
    }
}

