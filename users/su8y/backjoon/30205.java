import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    private static StringTokenizer st;
    private static int N,  M, s[][];
    private static long K;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        s = new int[N][M];
        for (int i = 0; i < N; i++) {
            s[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).limit(M).toArray();
        }
        for (int i = 0; i < N; i++) {
            Arrays.sort(s[i]);
        }

        for (int i = 0; i < N; i++) {
            int item_count = 0;
            for (int j = 0; j < M; j++) {
                if (s[i][j] == -1) item_count++;
                else if (K < s[i][j]) {
                    while (item_count > 0 && K < s[i][j]) {
                        K *= 2;
                        item_count--;
                    }
                    if (K < s[i][j]) {
                        System.out.println(0);return;
                    }
                    else K += s[i][j];
                }
                else K += s[i][j];
            }
            while (item_count-- > 0) K *= 2;

        }
        System.out.println(1);


        bw.close();
        br.close();
    }


}