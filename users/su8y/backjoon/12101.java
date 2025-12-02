import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    private static StringTokenizer st;
    private static int n, k, cache[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static Stack<Integer> record = new Stack<>();

    private static int solve(int n) {
        if (cache[n] != -1) return cache[n];
        return cache[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
    }

    private static void bt(int capacity) {
        if (capacity == 0) {
            if (--k == 0) {
                String collect = record.stream().map(String::valueOf).collect(Collectors.joining("+"));
                System.out.println(collect);
            }
        }
        for (int i = 1; i <= 3; i++) {
            if (capacity < i) continue;
            record.push(i);
            bt(capacity - i);
            record.pop();
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        bt(n);
        if(k > 0)  System.out.println(-1) ;

        bw.close();
        br.close();
    }


}