import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
                int[] answer = {};
        List<Integer> list = new ArrayList<>();
        int rear = 0, count = 0;

        // 리어가 array.length 보다 작을때까지 반복
        while(rear < progresses.length){
            // 93 이면 부족한 숫자만큼(7) speed * 7 더해줌
                        int times =(int) Math.ceil(((100 - progresses[rear])/ (double)speeds[rear]));

            for(int i = 0 ; i < progresses.length; i++){
                // 리어의 값과 차이를 곱해준다.
                progresses[i] += (times * speeds[i]);
            }
            // [100, 100++ , 90]
            while(rear < progresses.length && progresses[rear] >= 100){
                ++rear;
                ++count;
            }
            list.add(count);
            count=0;
        }
        return list.stream().mapToInt(i -> i).toArray();

    }
}