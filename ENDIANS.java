import java.io.*;
import java.io.BufferedReader;
class ENDIANS{
    public static void main(String[] arg){
        long []arr = new long[4];
        InputStream is = System.in;
        try{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String data = br.readLine();
        //System.out.println(data);
        int count = Integer.parseInt(data);
        for (int i=0 ; i<count ; i++){
            arr[i] = Long.parseLong(br.readLine());
            System.out.println(littleEndian(arr[i]));
        }
    }catch(IOException e){

    }
        System.exit(0);
    }
    public static long littleEndian(long src){
        long dest=0;
        dest = ((src>>24)&0xff) +((src>>8)&0xff00)+((src<<8)&0xff0000)+((src<<24)&0xff000000) ;
        return dest&0xFFFFFFFFL;
    }
}