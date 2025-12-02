import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static StringTokenizer st;
    private static int n, arr[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        //( 앞수 * a ) + b
        // 1 4 13 40 이면
        // n - b = (n - 1 * a);
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[n];
        for(int i = 0 ; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());

        }
        boolean flag = false;
        int result = 0;
        for (int a = -200; a < 201; a++) {
            for (int b = -100000; b < 100001; b++) {
                int i = 1;
                for (; i < n; i++) {
                    if (calculation(arr[i - 1], a, b) != arr[i]) break;
                }
                if (i == n) {
                    if(flag == true && calculation(arr[i-1],a,b) != result) {
                        System.out.println("A");
                        return;
                    }
                    result = calculation(arr[i - 1], a, b);
                    flag = true;
                }
            }
        }
        if(flag == false){
            System.out.println("B");
        }else{
            System.out.println(result);

        }

        bw.close();
        br.close();
    }

    private static int calculation(int n, int a, int b) {
        return n * a + b;
    }


}