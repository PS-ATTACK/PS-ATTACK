import java.io.*;
import java.util.StringTokenizer;

public class Main {


    private static StringTokenizer st;
    private static int n, r, c;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());


        int result = divide(n, r, c);

        bw.write(String.valueOf(result));
        bw.flush();
        bw.close();
        br.close();
    }

    static int count = 0;

    private static int divide(int n, int y, int x) {
        if (n == 0) return 0;
        int half = 1 << (n - 1);
        if (y < half && x < half) return divide(n - 1, y, x);
        else if (y < half && x >= half) return  half * half + divide(n - 1, y, x - half);
        else if (y >= half && x < half) return 2*half * half + divide(n - 1, y - half, x);
        else return 3 * half * half + divide(n - 1, y - half, x - half);
    }
}