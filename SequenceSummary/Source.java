import java.io.*;
import java.util.*;
import static java.lang.System.out;
//https://www.acmicpc.net/problem/13398
public class Source{
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int count = in.nextInt();
        int[] arr = new int[count];
        int[] maxCache = new int[count];
        int[] maxCache2 = new int[count];
        int max = -100000001;
        for(int i=0; i<count; i++){
            arr[i] = in.nextInt();
        }
        
        maxCache[0] = arr[0];
        for(int i=1; i<count; i++){//find max value in each position from 0
            if(maxCache[i-1] < 0)
                maxCache[i] = arr[i];//new set
            else
                maxCache[i] = maxCache[i-1] + arr[i];//sequence set
        }

        maxCache2[count-1] = arr[count-1];
        for(int i=count-2; i >= 0; i--){//find max value in each position from 0
            if(maxCache2[i+1] < 0)
                maxCache2[i] = arr[i];//new set
            else
                maxCache2[i] = maxCache2[i+1] + arr[i];//sequence set
        }

        // max(a which is max from 0 to i +  b which is max to count-1 from i, a, b)
        for(int i=0; i<count; i++){
            if(i==0){//special case
                if(max<maxCache2[0])
                    max = maxCache2[0];
            }else if(i==count-1){//special case
                if(max<maxCache[count-1])
                    max = maxCache[count-1];                
            }else{//max(a,b,c) case
                if(max<maxCache[i-1])
                    max = maxCache[i-1];
                else if(max<maxCache2[i])
                    max = maxCache2[i];
                else if(max<(maxCache[i-1] + maxCache2[i]))
                    max = maxCache[i-1] + maxCache2[i];
            }
            if(arr[i] < 0){//case of jump 1
                if(!(i-1 < 0 && i+1 >= count) 
                   && max < ((i-1 < 0 ? 0 : maxCache[i-1]) + (i+1 >= count ? 0 : maxCache2[i+1]))){
                    max = (i-1 < 0 ? 0 : maxCache[i-1]) + (i+1 >= count ? 0 : maxCache2[i+1]);
                }
            }
        }

        out.println(max);
    }
}

