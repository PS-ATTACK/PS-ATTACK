import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int count = 0;
        int n = Integer.parseInt(st.nextToken());
        for(int i = 0 ; i< n ;i++){
            st = new StringTokenizer(br.readLine(),"D-");

            if(Integer.parseInt(st.nextToken()) <= 90){
                count++;
            }
        }
        System.out.println(count);

    }
}
