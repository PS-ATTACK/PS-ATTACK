import java.io.*;
import java.util.StringTokenizer;

class Main{
    private static StringTokenizer st;
    private static int n,X ;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        int sum = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            sum += Integer.parseInt(st.nextToken());
        }
        System.out.println(sum % X == 0 ? "1":"0");


        bw.close();
        br.close();
    }


}