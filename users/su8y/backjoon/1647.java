import java.io.*;
import java.util.*;

class Main {
    private static StringTokenizer st;
    private static int n, g, parent[], m;
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static PriorityQueue<Road> pq = new PriorityQueue<>((o1, o2) -> o1.cost < o2.cost ? -1 : 1);
    private static Stack<Integer> stack = new Stack<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        parent = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            pq.add(new Road(a, b, cost));
        }
        while (!pq.isEmpty()) {
            Road road = pq.poll();
            int a = road.a;
            int b = road.b;
            int cost = road.cost;
            int p_a = findParent(a);
            int p_b = findParent(b);
            if (p_a == p_b) continue;

            if (p_a < p_b) parent[p_b] = parent[p_a];
            else parent[p_a] = parent[p_b];
            stack.add(cost);
        }

        if(!stack.isEmpty()) stack.pop();
        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        System.out.println(result);


    }

    private static int findParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }


}

class Road {
    int a;
    int b;
    int cost;

    public Road(int a, int b, int cost) {
        this.a = a;
        this.b = b;
        this.cost = cost;
    }
}