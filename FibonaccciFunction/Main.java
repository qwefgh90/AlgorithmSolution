import java.math.*;
import java.io.*;
import java.util.*;
import static java.lang.System.out;
//https://www.acmicpc.net/problem/1003
public class Main{

    private static class Fibo{
        public int zero;
        public int one;
        public Fibo(){}
        public Fibo(int zero, int one){
            this.zero = zero;
            this.one = one;
        }
    }
    public static void main(String[] argv){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        Fibo[] cache = new Fibo[41];
        cache[0] = new Fibo(1,0);
        cache[1] = new Fibo(0,1);
        for(int i=2; i<41; i++){
            cache[i] = new Fibo();
            cache[i].one = cache[i-1].one + cache[i-2].one;
            cache[i].zero = cache[i-1].zero + cache[i-2].zero;
        }
        int n = in.nextInt();
        
        for(int i=0; i<n; i++){
            int k = in.nextInt();
            out.println(String.valueOf(cache[k].zero) + " " + String.valueOf(cache[k].one));
        }
        
        
    }
}

