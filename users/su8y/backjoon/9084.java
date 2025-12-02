import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    private static StringTokenizer st;
    private static int n;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static int t;
    private static int[] arr;
    private static int[][] cache;
    private static int m;

    public static void main(String[] args) throws IOException {
        // N 개의 동전 {N1 N2...}으로 M원을 만드는 경우의 수
        t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            n = Integer.parseInt(br.readLine());
            arr = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            for (int i1 = 1; i1 < n + 1; i1++) {
                arr[i1] = Integer.parseInt(st.nextToken());
            }
            m = Integer.parseInt(br.readLine());
            cache = new int[n + 1][m + 1];
            for (int i1 = 0; i1 < n + 1; i1++) {
//                Arrays.fill(cache[i1], -1);
                cache[i1][0] = 1;
            }
            // M = M - cost[n..];
            System.out.println(pack(n, m));

        }


        bw.close();
        br.close();
    }
    // 1 , 2가 있을때 1000원을 만드는 것은 ?
    // 100, 200 으로 300원을 만드는 것은 ?
    // 100원으로 만드는 것 300원은
    // cache[i-1][m-cost[i]]

    private static int pack(int coin, int capacity) {
        if (coin < 1 || capacity < 0) return 0;
        if (cache[coin][capacity] != 0) return cache[coin][capacity];

        int result = pack(coin - 1, capacity);
        result += pack(coin, capacity - arr[coin]);
        return cache[coin][capacity]
                = result;
    }


}