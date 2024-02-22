import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    private static StringTokenizer st;
    private static int n, m, k, arr[], cache[][];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static List<List<Integer>> friends = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        cache = new int[n + 1][n + 1];
        m = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            if (i + 1 <= n && arr[i] == arr[i + 1]) cache[i][i + 1] = 1;
            cache[i][i] = 1;
        }
        for (int j = 2; j < n; j++) {
            for (int start = 1; j + start <= n; start++) {
                if (start + j <= n && start + 1 <= n) {
                    if (arr[start] == arr[start + j] && cache[start + 1][start + j - 1] == 1)
                        cache[start][start + j] = 1;
                }
            }
        }


        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int sta = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            bw.write(solve(sta, end) ? "1\n" : "0\n");
        }// Input :: end
        bw.flush();
        bw.close();
    }


    private static boolean solve(int start, int end) {
        if (cache[start][end] == 0) return false;
        return true;
    }


}