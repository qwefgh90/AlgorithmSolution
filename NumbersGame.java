// this is a problem in https://www.acmicpc.net/problem/4335
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.InputStream;
import java.util.Optional;
public class NumbersGame {
    public static BufferedReader createBufferedReader(InputStream in){
        return new BufferedReader(new InputStreamReader(in));
    }
    private final static String TOO_HIGH = "too high";
    private final static String TOO_LOW = "too low";
    private final static String RIGHT_ON = "right on";
        
    public static boolean checkTruth(int min, int max, Optional<Integer> numberOpt){
        if(numberOpt.isPresent()){
            final int number = numberOpt.get();
            if(number > min && number < max)//between
                return true;
            else
                return false;
        }else{
            if(min + 1 >= max)//lie
                return false;
            else
                return true;
        }
    }

    public static void main(String[] args) throws Exception{
        int min = 0;
        int max = 11;
        boolean state = true;
        try(BufferedReader br = createBufferedReader(System.in)){
            String numberString = "";
            while((numberString = br.readLine()) != null){
                final int number = Integer.parseInt(numberString);
                if(number == 0)
                    break;
                final String wordToSay = br.readLine();
                Optional<Integer> numberWhenRightOn = Optional.empty();
                if(wordToSay.equals(TOO_HIGH) && number < max){
                    max = number;
                    state = state && checkTruth(min, max, numberWhenRightOn);
                }else if(wordToSay.equals(TOO_LOW) && number > min){
                    min = number;
                    state = state && checkTruth(min, max, numberWhenRightOn);
                }else if(wordToSay.equals(RIGHT_ON)){
                    numberWhenRightOn = Optional.of(number);
                    state = state && checkTruth(min, max, numberWhenRightOn);
                    if(state)
                        System.out.println("Stan may be honest");
                    else 
                        System.out.println("Stan is dishonest");
                    state = true;
                    min = 0;
                    max = 11;
                }
            }
        }
    }
}
