import java.io.*;
import java.util.StringTokenizer;

class Main {
    private static StringTokenizer st;
    private static int N, K, lineOfLans[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        lineOfLans = new int[N];
        for (int i = 0; i < N; i++) {
            lineOfLans[i] = Integer.parseInt(br.readLine());
        }

        long lo = 1;
        long hi = Integer.MAX_VALUE;
        hi++;
        while (lo + 1 < hi) {
            long mid = (lo + hi) / 2;
            //더 적은 값이라면 값을 올려야 hi를 내려서 한번더 확인한다.
            if (slice(mid)) lo = mid;
            else hi = mid;
        }
        System.out.println(hi - 1);


        bw.close();
        br.close();
    }

    private static boolean slice(long n) {
        int count = 0;
        for (int lineOfLan : lineOfLans) {
            long result_sliceLineOfLan = lineOfLan / n;
            count += result_sliceLineOfLan;
        }
        return count >= K;
    }


}