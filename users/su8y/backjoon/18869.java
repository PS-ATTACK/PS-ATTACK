import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    private static StringTokenizer st;
    private static int n, m, space[][], sortedSpace[], cache[];
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        space = new int[m][n];
        cache = new int[100000];
        Arrays.fill(cache, -1);
        for (int universeIndex = 0; universeIndex < m; universeIndex++) {
            st = new StringTokenizer(br.readLine());
            for (int spaceIndex = 0; spaceIndex < n; spaceIndex++) {
                space[universeIndex][spaceIndex] = Integer.parseInt(st.nextToken());
            }
            sortedSpace = space[universeIndex].clone();
            Arrays.sort(sortedSpace);
            for (int i = 0; i < n; i++) {
                space[universeIndex][i] = binary_search(space[universeIndex][i]);
            }
        }

        int count = 0;
        Map<String, Integer> setString = new HashMap<>();
        for (int[] ints : space) {
            String collect = Arrays.stream(ints).mapToObj(String::valueOf).collect(Collectors.joining());
            if (setString.containsKey(collect)) {
                setString.put(collect, setString.get(collect) + 1);
            } else setString.put(collect, 1);
        }
        for (Map.Entry<String, Integer> stringIntegerEntry : setString.entrySet()) {
            Integer value = stringIntegerEntry.getValue();
            if (value == 2) count += 1;
            else if (value > 2)
//                count += factorial(value) / ((factorial(2) * factorial(value - 2)));
                count += getCombination(value, 2);
        }
        bw.write(count + "\n");


        bw.close();
        br.close();
    }

    private static int factorial(int number) {
        // r
        if (number <= 1) return number;
        if (cache[number] != -1) return cache[number];
        return cache[number] = factorial(number - 1) * number;
    }

    private static int getCombination(int n, int r) {
        if (n == r || r == 0) return 1;
        else return getCombination(n - 1, r - 1) + getCombination(n - 1, r);
    }

    private static int binary_search(int number) {
        int lo = -1, hi = n - 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (sortedSpace[mid] < number) lo = mid;
            else hi = mid;
        }
        return hi;
    }


}