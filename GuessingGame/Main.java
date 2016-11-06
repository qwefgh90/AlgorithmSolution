import java.io.*;
import java.util.*;
import static java.lang.System.out;
//https://www.acmicpc.net/problem/4335

public class Main{
    
    private static final String MSG_HIGH = "too high";
    private static final String MSG_LOW = "too low";
    private static final String MSG_RIGHT = "rigsht on";
    
    private static final int TOO_LOW = -1;
    private static final int TOO_HIGH = 1;
    private static final int NOINFO = 0;
    private static void initCheckList(int[] arr){
        for(int i=0; i<arr.length; i++){
            arr[i] = NOINFO;
        }
    }
    
    private static class Pair{
        public int num;
        public String msg;
        public Pair(int num, String msg){
            this.num = num;
            this.msg = msg;
        }
    }

    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        
        int[] checkList = new int[11];
        
        int ele = 0;
        LinkedList<Pair> ll = new LinkedList<>();
        while(0 != (ele = in.nextInt())){
            in.nextLine();
            String msg = in.nextLine();
            ll.addFirst(new Pair(ele, msg));
        }
        while(!ll.isEmpty()){
            Pair p = null;
            p = ll.removeLast();
            if(p.num == 0)
                break;
            
            if((checkList[p.num] == NOINFO) && p.msg.equals(MSG_HIGH)){
                checkList[p.num] = TOO_HIGH;
            }else if((checkList[p.num] == NOINFO) && p.msg.equals(MSG_LOW)){
                checkList[p.num] = TOO_LOW;
            }else{
                //if strange state
                if((p.msg.equals(MSG_HIGH) && checkList[p.num] == TOO_LOW)
                   || (p.msg.equals(MSG_LOW) && checkList[p.num] == TOO_HIGH)){
                    Pair pair = null;
                    while((pair = ll.removeLast()) != null //remove to right
                          && !pair.msg.equals(MSG_RIGHT)){
                    }
                    out.println("Stan is dishonest");
                    initCheckList(checkList);
                }
                else if(p.msg.equals(MSG_RIGHT)){
                    for(int i=0; i<checkList.length; i++){
                        if(checkList[i] == TOO_HIGH && i <= p.num){//if lie
                            out.println("Stan is dishonest");
                            initCheckList(checkList);
                            break;
                            
                        }else if(checkList[i] == TOO_LOW && i >= p.num){//if lie
                            out.println("Stan is dishonest");
                            initCheckList(checkList);
                            break;
                        }
                        if( i == checkList.length -1){//all pass
                            out.println("Stan is honest");
                            initCheckList(checkList);
                        }
                    }
                }
            }
        }
    }
}
