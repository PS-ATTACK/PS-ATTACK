import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    private static int n, m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        HashSet<String> s1 = new HashSet<>();
        HashSet<String> s2 = new HashSet<>();

        // input data
        for (int i = 0; i < n; i++) s1.add(br.readLine());
        for (int i = 0; i < m; i++) s2.add(br.readLine());

        // clustering
        s1.retainAll(s2);

        // sorting
        TreeSet<String> sortedSet = new TreeSet<>();
        sortedSet.addAll(s1);

        // print
        System.out.println(sortedSet.size());
        sortedSet.iterator().forEachRemaining(System.out::println);

        br.close();
    }


}
