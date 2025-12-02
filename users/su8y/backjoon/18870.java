import java.io.*;
import java.util.*;

public class Main {
    private static StringTokenizer st;
    private static int n, numbers[];
    private static SortedSet<Integer> set = new TreeSet<>();
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static Integer[] sortedNumbers;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        numbers = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
            set.add(numbers[i]);
        }
        sortedNumbers = set.toArray(new Integer[0]);

        for (int i = 0; i < n; i++) {
            bw.write(binary_search(numbers[i]) + " ");
        }


        bw.flush();
        bw.close();
        br.close();
    }

    private static int binary_search(int number) {
        int lo = -1, hi = sortedNumbers.length-1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;

            if (sortedNumbers[mid] < number) lo = mid;
            else hi = mid;
        }
        return hi;
    }


}