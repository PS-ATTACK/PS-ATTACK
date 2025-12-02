import java.io.*;
import java.util.*;

public class Main {
    // 1은 하나씩 있지만 , 00은 한쌍의 타일들만이 남는다.
    private static StringTokenizer st;
    private static int n, cache[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        if (n <= 2) {
            System.out.println(n);
            return;
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        q.add(2);


        for (int i = 3; i <= n; i++) {
            int n2 = q.poll();
            int n1 = q.peek();
            q.add((n1 + n2)%15746);
        }
        q.poll();
        System.out.println(q.peek());

        bw.close();
        br.close();
    }

    private static int solve(int n) {
        if (cache[n] != -1) return cache[n];

        return cache[n] = (solve(n - 1) + solve(n - 2)) % 15746;
    }


}