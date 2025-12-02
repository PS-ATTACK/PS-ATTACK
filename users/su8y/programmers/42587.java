import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int solution(int[] priorities, int location) {
                int answer = 0;
        int len = priorities.length;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0 ; i < len; i++){
            pq.add(priorities[i]);
        }
        while(!pq.isEmpty()){
            for(int i = 0 ; i < len; i++){
                if(priorities[i] == pq.peek()){
                    if(location == i){
                        return ++answer;
                    }

                    ++answer;
                    pq.poll();
                }
            }
        }
        return -1;

    }
}