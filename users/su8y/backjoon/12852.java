import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static StringTokenizer st;
    private static int n, cache[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final int multiply[] = {2, 3};

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        cache = new int[n + 1];
        Arrays.fill(cache, Integer.MAX_VALUE);

        cache[1] = 0;
        for (int i = 1; i <= n; i++) {
            if (calculation(i + 1))
                cache[i + 1] = Math.min(cache[i] + 1, cache[i + 1]);
            for (int j = 0; j < 2; j++) {
                if (calculation(i * multiply[j]))
                    cache[i * multiply[j]] = Math.min(cache[i * multiply[j]], cache[i] + 1);
            }
        }

        int result = cache[n];
        System.out.println(result);

        int count = result - 1;
        List<Integer> list = new ArrayList<>();
        list.add(n);

        while (n > 0 && count >= 0) {
            if (cache[n - 1] == count) {
                list.add(n  - 1);
                n -= 1;
                count--;
                continue;
            }  if (n % 2 == 0 && cache[n / 2] == count) {
                list.add(n/2);
                n /= 2;
                count--;
                continue;

            } if (n % 3 == 0 && cache[n / 3] == count) {
                list.add(n/3);
                n /= 3;
                count--;
            }
        }

        list.forEach(e -> System.out.print(e + " "));

        bw.close();
        br.close();
    }

    private static boolean calculation(int a) {
        if (a < 0 || a > n) return false;
        return true;
    }


}