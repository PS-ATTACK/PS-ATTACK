import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static StringTokenizer st;
    private static int n, m, tree[],cache[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        // 딱 필요한 만큼의 나무만 가져갈 수 있게 범위를 설정한다.
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        // T T T T F F F ...
        // 으로 되어있기 때문에 T일때 가장 큰 값을 가지면 된다 .

        tree = new int[n];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) tree[i] = Integer.parseInt(st.nextToken());

        int lo = -1, hi = 1_000_000_001;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (sliceTree(mid)) lo = mid;
            else hi = mid;
        }
        System.out.println(lo);


        bw.close();
        br.close();
    }

    private static boolean sliceTree(int length) {
        long slicedTree = 0;
        for (int i = 0; i < n; i++) {
            long result = tree[i] - length;
            if(result < 0 ) continue;
            slicedTree += result;
        }
        return slicedTree >= m;
    }


}