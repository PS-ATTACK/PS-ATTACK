import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
예제 입력 1
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

예제 출력 1
3


LIS A 나 B 플레이스중에서 하나를 정렬을 하게되면
다른 하나의 포인트는 LIS를 만족할때 교차하지 않는 선분 그룹을 가지게 된다

DP로 시간복잡도 O(n^2)에 풀수 있지만 바이너리 서치를 사용해서 O(NlogN)으로 풀수 있다. 

start + 1을 해줌으로써 시작지점을 for문으로 계속 돌아야 하는 것을 해결해줬지만 n+1개의 caching을 하기 때문에
결과 값이 +1된 상태로 나온다. 그래서 lis()를 호출하고 난 결과물에대해서 -1을 해줘야지 최종 결과물을 받아볼 수 있따. 



*/
public class Main {
    private static StringTokenizer st;
    private static int n, dp[], map[][];
    private static List<Pair> graph;
    private static List<Integer> list_target_arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        dp = new int[n];
        map = new int[n][2];

        graph = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            // a point
            int a = Integer.parseInt(st.nextToken());
            // b point
            int b = Integer.parseInt(st.nextToken());
            graph.add(new Pair(a, b));
        }
        // 1개의 사이트 기준으로 정렬  상태: 다른 한개의 사이트는 뒤죽박죽
        Collections.sort(graph);

        graph.iterator().forEachRemaining(e -> list_target_arr.add(e.x));

        dp = new int[n + 1];
        Arrays.fill(dp, -1);
        int result = lis(-1) - 1;

        System.out.println(graph.size() - result);

        br.close();
    }

    private static int lis(int start) {
        if (dp[start + 1] != -1) return dp[start + 1];

        dp[start + 1] = 1;
        for (int next = start + 1; next < list_target_arr.size(); next++) {
            if (start == -1 || list_target_arr.get(start) < list_target_arr.get(next))
                dp[start + 1] = Math.max(dp[start + 1], lis(next) + 1);
        }
        return dp[start + 1];
    }


}

class Pair implements Comparable<Pair> {
    int y;
    int x;

    public Pair(int y, int x) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair o) {
        return this.y - o.y;
    }
}