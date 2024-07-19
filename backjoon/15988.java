import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    private static StringTokenizer st;
    private static int n, k, cache[], t, arr[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static Stack<Integer> record = new Stack<>();

    private static final int MODULAR_VALUE = 1_000_000_009;

    private static int solve(int n) {
        if (cache[n] != -1) return cache[n];
        return cache[n] = (solve(n - 1) + solve(n - 2) + solve(n - 3)) % MODULAR_VALUE;
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
        t = Integer.parseInt(br.readLine());
        arr = new int[t];
        for (int i = 0; i < t; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int maxValue = Arrays.stream(arr).max().getAsInt();
        cache = new int[maxValue + 1];
        Arrays.fill(cache, -1);
        cache[0] = 0;
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 4;
        for (int i = 4; i <= maxValue; i++) {
            cache[i] = ((cache[i - 3] + cache[i - 2]) % MODULAR_VALUE + cache[i - 1]) %MODULAR_VALUE;
        }
        for (int i = 0; i < t; i++) {
            bw.write(cache[arr[i]] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }


}