class Solution {
    boolean solution(String str) {
      
        boolean answer = true;
        int add = 0;



            for(int i = str.length()-1; i >=0 ; i--){

      
            if(str.charAt(i) == '('){
                add--;
            }
            else {
                add++;
            }

            if(add == -1){
                break;
            }
        }

        if(add != 0){
            answer = false;
        }

        return answer;
    }
}