//https://www.acmicpc.net/problem/3136
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Optional;
import java.util.Set;
import java.util.HashSet;
public class GroundPlan {

    static class Edge{
        public Edge(Position src, Position dst){
            this.src = src;
            this.dst = dst;
        }
        public final Position src;
        public final Position dst;
        public String toString(){
            return src.toString() + "->" + dst.toString();
        }
    }
    static class Position{
        public Position(int x, int y){
            this.x = x;
            this.y = y;
        }
        public final int x;
        public final int y;
        public String toString(){
            return x + "," + y;
        }
        public Position move(char command){
            switch(command){
            case '0':
                return new Position(this.x, this.y+1);
            case '1':
                return new Position(this.x+1, this.y+1);
            case '2':
                return new Position(this.x+1, this.y);
            case '3':
                return new Position(this.x+1, this.y-1);
            case '4':
                return new Position(this.x, this.y-1);
            case '5':
                return new Position(this.x-1, this.y-1);
            case '6':
                return new Position(this.x-1, this.y);
            case '7':
                return new Position(this.x-1, this.y+1);
            default:
                throw new RuntimeException("invalid command");
            }
        }
        public String toConnectString(Position p2){
            return new Edge(this, p2).toString();
        }
        public Optional<Edge> getCrossEdge(Position p2){
            if((Math.abs(this.x - p2.x) == 1) && (Math.abs(this.y - p2.y) == 1))
                return Optional.of(new Edge(new Position(this.x, p2.y), new Position(p2.x, this.y)));
            else
                return Optional.empty();
        }
    }

    public static void main(String[] args) {
        final Scanner s = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        Set<String> positions = new HashSet<String>();
        Set<String> edges = new HashSet<String>();
        int result = 0;
        positions.add(new Position(0,0).toString());
        int inputCount = s.nextInt();
        char[] numbers = s.next().toCharArray();
        Position currentPosition = new Position(0,0);
        for(int i=0; i<numbers.length; i++){
            final Position nextPosition = currentPosition.move(numbers[i]);

            if(!(edges.contains(currentPosition.toConnectString(nextPosition)))){
                if(positions.contains(nextPosition.toString())){
                    result += 1;
                }
                final Optional<Edge> crossEdgeOpt = currentPosition.getCrossEdge(nextPosition);
                if(crossEdgeOpt.isPresent()){
                    if(edges.contains(crossEdgeOpt.get().toString())){
                        result += 1;
                    }
                }
            }
            positions.add(currentPosition.toString());
            edges.add(currentPosition.toConnectString(nextPosition));
            edges.add(nextPosition.toConnectString(currentPosition));
            currentPosition = nextPosition;
        }
        System.out.println(result);
    }
}
