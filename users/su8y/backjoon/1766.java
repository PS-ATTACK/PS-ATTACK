import java.io.*;
import java.util.*;

class Main {
    private static StringTokenizer st;
    private static int n, m, degree[];
    private static List<List<Integer>> graph;
    private static PriorityQueue<Integer> queue = new PriorityQueue<>();
    private static Queue<Integer> result = new LinkedList<>();
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }
        degree = new int[n + 1];
        Arrays.fill(degree, 0);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            graph.get(start).add(end);
            degree[end]++; //진입차수 증가
        }

        //진입차수 0인것들 큐에 집어넣기
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) queue.add(i);
        }

        while (!queue.isEmpty()) {
            Integer here = queue.poll();
            result.add(here);

            for (int there : graph.get(here)) {
                if (--degree[there] == 0) queue.add(there);
            }

        }
        // 안넣고 남은것들 추가해주기
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1) {
                System.out.println(0);
                return;
            }
        }

        printQueue();

        bw.close();
        br.close();
    }

    private static void printQueue() {
        Iterator<Integer> iterator = result.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

    }


}