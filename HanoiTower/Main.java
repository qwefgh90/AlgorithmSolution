import java.math.*;
import java.io.*;
import java.util.*;
import static java.lang.System.out;
//https://www.acmicpc.net/problem/1914
//hanoi tower
public class Main{
    private static StringBuffer outBuffer = new StringBuffer();
    private static ArrayList<ArrayList<Integer>> hanoi = new ArrayList<>();
    private static int[] cache = new int[101];
    static{
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
        ArrayList<Integer> arr3 = new ArrayList<>();
        hanoi.add(arr1);
        hanoi.add(arr2);
        hanoi.add(arr3);
        for(int i=0; i<cache.length; i++){
            cache[i] = -1;
        }
    }

    public static void main(String[] argv){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = in.nextInt();
        
        for(int i=n; i>0; i--){
            hanoi.get(0).add(i);
        }

        if(n <= 20){
            int k = f(n, 1, 3, true);
            out.println(k);
            out.println(outBuffer.toString());
        }else{// caculate result for (2^100 - 1)
            //count of N piece moving in hanoi equals to Geometric progression
            BigInteger result = new BigInteger("2");;
            final BigInteger big = new BigInteger("2");
            //int k = f(n, 1, 3, false); //C(n) = C(n-1) + 1
            for(int i=0; i<n-1; i++){
                result = result.multiply(big);
            }
            out.println(result.subtract(new BigInteger("1")));
        }
    }
    
    static int f(int n, int from, int to, boolean printYn){
        int step1 = 0;
        if(n-1 == 0)
            step1 = 0;//nothing
        else{
            if(printYn)
                step1 = f(n-1, from, other(from, to), printYn);
            else{
                if(cache[n-1] != -1)
                    step1 = cache[n-1];
                else
                    step1 = f(n-1, from, other(from, to), printYn);
            }
        }
        
        if(printYn)
            outBuffer.append(from + " " + to + "\n");

        ArrayList<Integer> fromArray = hanoi.get(from-1);
        ArrayList<Integer> toArray = hanoi.get(to-1);
        toArray.add(fromArray.remove(0));
        int step2 = 1;

        int step3 = 0;
        if(n-1 == 0)
            step3 = 0;//nothing
        else{
            if(printYn)
                step3 = f(n-1, other(from,to), to, printYn);
            else{
                if(cache[n-1] != -1)
                    step3 = cache[n-1];
                else
                    step3 = f(n-1, other(from,to), to, printYn);
            }
        }
        cache[n] = step1 + step2 + step3;

        return cache[n];
        
    }

    private static void initSet(boolean[] set){
        for(int i=0; i<set.length; i++){
            set[i] = false;
        }
    }

    private static int other(int a, int b){
        final boolean[] set = new boolean[3];
        initSet(set);
        set[a-1] = true;
        set[b-1] = true;
        for(int i=0; i<set.length; i++){
            if(set[i] == false)
                return i+1;
        }
        return -1;
    }
}

