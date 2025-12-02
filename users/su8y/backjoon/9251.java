import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        String b = br.readLine();

        System.out.println(LCS(a,b));


    }
    private static int LCS(String a, String b){
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
        return cache[a.length()][b.length()];
    }
}