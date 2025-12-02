import java.io.*;
import java.util.StringTokenizer;

public class Main {
    // 조카의 수 M 과자수 의 N
    private static StringTokenizer st;
    private static int n, m, snack[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        snack = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            snack[i] = Integer.parseInt(st.nextToken());
        }


        int lo = 0, hi = 1_000_000_001;

        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (distributing(mid)) lo = mid;
            else hi = mid;
        }
        System.out.println(lo);


        bw.close();
        br.close();
    }

    private static boolean distributing(int length) { // mid 높이의 사탕 잘랐을때 m개의 사탕을 얻을수 있는가
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += snack[i] / length;
        }
        return count >= m;

    }


}