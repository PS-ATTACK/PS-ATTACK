import java.io.*;
import java.util.*;

/**
 * 3
 * 1.0 1.0
 * 2.0 2.0
 * 2.0 4.0
 */
class Main {
    private static StringTokenizer st;
    private static int n, m, parents[];
    private static List<Star> stars = new ArrayList<>();
    private static PriorityQueue<Cost> costs = new PriorityQueue<>((o1, o2) -> o1.v <= o2.v ? -1 : 1);
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        parents = new int[n];
        for (int i = 0; i < n; i++) {
            // init
            parents[i] = i;
            st = new StringTokenizer(br.readLine());

            double y = Double.parseDouble(st.nextToken());
            double x = Double.parseDouble(st.nextToken());
            stars.add(new Star(y, x));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                Star a = stars.get(i);
                Star b = stars.get(j);
                double calculatedDistance = calculateDistance(a, b);
                costs.add(new Cost(i, j, calculatedDistance));
            }
        }
        double result = 0;

        while (!costs.isEmpty()) {
            Cost v = costs.poll();
            double distance = v.v;
            int i = v.a;
            int j = v.b;
            int i_parent = findParent(i);
            int j_parent = findParent(j);
            if (i_parent == j_parent) continue;

            if (i_parent < j_parent) parents[j_parent] = parents[i_parent];
            else parents[i_parent] = parents[j_parent];
            result += distance;
        }
        System.out.printf("%.2f",result);

    }

    private static int findParent(int n) {
        if (parents[n] == n) return n;
        return parents[n] = findParent(parents[n]);
    }

    private static double calculateDistance(Star a, Star b) {
        double v = Math.pow(a.y - b.y, 2) + Math.pow(a.x - b.x, 2);
        return Math.sqrt(v);
    }


}

class Cost {
    int a;
    int b;
    double v;

    public Cost(int a, int b, double v) {
        this.a = a;
        this.b = b;
        this.v = v;
    }
}

class Star {
    double y;
    double x;

    public Star(double y, double x) {
        this.y = y;
        this.x = x;
    }
}