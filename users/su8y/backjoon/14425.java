import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int cnt = 0;

        Set<String> aggregate = new HashSet<>();

        for (int i = 0; i < n; i++) aggregate.add(br.readLine());
        for (int i = 0; i < m; i++) if (aggregate.contains(br.readLine())) cnt++;

        System.out.println(cnt);
        br.close();
    }

}
