import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        String b = br.readLine();

        int cache[][] = LCS(a,b);
        System.out.println(cache[cache.length -1][cache[0].length - 1]);
        String result = LCS_recursion(a,b,cache);
        System.out.println(result);


    }

    private static String LCS_recursion(String a, String b, int[][] cache) {
        StringBuilder builder= new StringBuilder();
        int y = cache.length - 1; int x = cache[0].length - 1;
        while(cache[y][x] != 0){
            if(cache[y][x] == cache[y-1][x]){
                y--;
            } else if (cache[y][x] == cache[y][x - 1]) {
                x--;
            }
            else{
                builder.append(a.charAt(y - 1));
                y--; x--;
            }

        }

        return builder.reverse().toString();
    }

    private static int[][] LCS(String a, String b){
        int cache[][] = new int[a.length() + 1][b.length() +1];

        for(int y = 1; y <= a.length(); y++){
            for (int x = 1; x <= b.length(); x++) {
                if(a.charAt(y-1) == b.charAt(x-1)){
                    cache[y][x] = cache[y-1][x-1] + 1;
                }
                else{
                    cache[y][x] = Math.max(cache[y-1][x],cache[y][x-1]);
                }
            }
        }
        return cache;
    }
}
