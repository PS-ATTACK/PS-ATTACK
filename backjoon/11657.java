 

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
 
class Pair<T,U> implements Comparable<Pair<T,U>> {
    private T first;
    private U second;

    Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }

    @Override
    public int compareTo(Pair<T, U> o) {
        return (int) this.first - (int)o.first;
    }
}

public class Main {
    static int N;
    static int M;
    static List<List<Pair>> adj;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for(int i = 0 ; i<= N;i++){
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            //first cost second endvertax
            adj.get(start).add(new Pair(cost, end));
        }

        long[] dist =spfa(1);
        if (dist!= null){
            for(int i = 2; i <= N ; i++){
                System.out.println(dist[i]);
            }
        }else{
            System.out.println(-1);
        }
    }
    public static long[] spfa(int start){
        boolean[] inq = new boolean[N+1];
        long[] dist = new long[N+1];
        Arrays.fill(dist,Long.MAX_VALUE);
        int[] visited = new int[N+1];
        Queue<Integer> q = new LinkedList<>();

        q.offer(start);
        inq[start] = true;
        dist[start] = 0;
        visited[start] = 1;

        while (!q.isEmpty()) {
            int here = q.peek(); q.poll();
            inq[here] = false;
            for(Pair i : adj.get(here)){
                int there = (int) i.getSecond();
                int thereCost = (int) i.getFirst();
                if(dist[there] > dist[here] + thereCost){
                    dist[there] = dist[here] + thereCost;
                    if(!inq[there]){
                        visited[there]++;
                        if(visited[here] >= N){
                            return null;
                        }
                        q.offer(there);
                        inq[there] = true;
                    }
                }
            }
        }
        for(int i = 2; i <=N; i++){
            dist[i] =dist[i] == Long.MAX_VALUE ? -1 :dist[i];
        }

        return dist;

    }
}
