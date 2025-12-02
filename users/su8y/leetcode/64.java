class Solution {

    class Pair<T,Integer> implements Comparable<Pair<T,Integer>> {
    private T first;
    private Integer second;

    Pair(T first, Integer second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public Integer getSecond() {
        return second;
    }

    @Override
    public int compareTo(Pair<T, Integer> o) {
        return (int) this.second - (int)o.second;
    }
}

    final static int[] x = {1, 0};
    final static int[] y = {0, 1};
    public int minPathSum(int[][] grid) {
    //Dandelions

        PriorityQueue<Pair<Pair<Integer, Integer>, Integer>> pq = new PriorityQueue<>();
//        PriorityQueue<AbstractMap.SimpleEntry<AbstractMap.SimpleEntry<Integer, Integer>, Integer>> pq = new PriorityQueue<>();

        int[][] dist = new int[grid.length][grid[0].length];
        for (int[] column : dist) {
            Arrays.fill(column, 9999);
        }

        pq.offer(new Pair(new Pair(0, 0),grid[0][0]));
        dist[0][0] = grid[0][0];

        while (!pq.isEmpty()) {
            int herex = pq.peek().getFirst().getFirst();
            int herey = pq.peek().getFirst().getSecond();
            int cost = pq.peek().getSecond();
            pq.poll();

            if (dist[herey][herex] < cost) continue;

            for (int i = 0; i < 2; i++) {
                int dx = herex + x[i];
                int dy = herey + y[i];
                if (dx >= 0 && dx < dist[0].length && dy >= 0 && dy < dist.length) {

                    int nextDist = cost + grid[dy][dx];

                    if (nextDist < dist[dy][dx]) {
                        pq.offer(new Pair(new Pair(dx, dy), nextDist));
                        dist[dy][dx] = nextDist;
                    }
                }
            }

        }


        return dist[dist.length - 1][dist[0].length - 1];

    }
}