import java.util.*;

class Pair<K,V>{
    K x;
    V y;

    public Pair(K x, V y) {
        this.x = x;
        this.y = y;
    }

    public K getX() {
        return x;
    }

    public void setX(K x) {
        this.x = x;
    }

    public V getY() {
        return y;
    }

    public void setY(V y) {
        this.y = y;
    }
}
class Solution{
    static int[] dx = {-1,0,1,0};
    static int[] dy = {0,-1,0,1};
    public int solution(int[][] maps) {
        int answer = 0;
        int[][] visited = new int[maps.length][maps[0].length];
        Queue<Pair<Pair<Integer, Integer>,Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(new Pair<>(0, 0),1));
        visited[0][0] = 1;
        while(!q.isEmpty()){
            int herex = q.peek().x.x;
            int herey = q.peek().x.y;
            int hereCost = q.peek().y;
            q.poll();
            for(int i = 0 ; i < 4; i++){
                int therey = herey + dy[i];
                int therex = herex + dx[i];
                int thereCost = hereCost + 1;
                if((0 <= therex && therex < visited[0].length)
                        && (0 <= therey && therey < visited.length)
                        && maps[therey][therex] == 1
                        && visited[therey][therex] == 0 ){
                    if (therex == visited[0].length-1 && therey == visited.length-1) {
                        return thereCost;

                    }
                    visited[therey][therex] = thereCost;
                    q.offer(new Pair<>(new Pair<>(therex, therey),thereCost));
                }
            }

        }
        return -1;
    }
}
