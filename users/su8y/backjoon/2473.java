import java.io.*;
import java.util.Arrays;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

class Main {
    private static StringTokenizer st;
    private static int n, water[];
    private static int result_indexs[] = new int[3];
    private static long max_weight = Long.MIN_VALUE;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        water = new int[n];
        for (int i = 0; i < n; i++) {
            water[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(water);

        for (int i = 0; i < n - 2; i++) { // n-2 2개의 포인터가 존재하기 때문에
            int lo = i + 1;
            int hi = n - 1;
            while (lo < hi) {
                long sum =  water[i] + ( (long)water[lo] + water[hi]);
                long weight_result = -Math.abs(sum);
                if (max_weight < weight_result) {
                    max_weight = weight_result;
                    result_indexs[0] = i;
                    result_indexs[1] = lo;
                    result_indexs[2] = hi;
                }
                if (sum <= 0) {
                    lo++;
                } else {
                    hi--;
                }
            }

        }

        for (int resultIndex : result_indexs) {
            System.out.print(water[resultIndex] + " ");
        }

        bw.close();
        br.close();
    }


}