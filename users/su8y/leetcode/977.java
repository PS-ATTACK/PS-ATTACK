class Solution {
    public int[] sortedSquares(int[] nums) {
        int[] arr ;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i : nums){
            int num = (int)Math.pow(i,2);
            //pq의 add 메소드는 IllegalStateEx.. offer은 false 를 반환한다.
            pq.offer(num);
        }
        arr = new int[pq.size()];
        for(int i = 0, len = pq.size() ; i< len; i++){
            arr[i] = pq.poll();
        }


        return arr; 
    }
}