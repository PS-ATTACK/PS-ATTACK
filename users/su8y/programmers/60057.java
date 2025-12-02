import java.util.List;
import java.util.ArrayList;
import java.lang.Math.*;
class Solution {
        public int solution(String s){
        int answer = Integer.MAX_VALUE;
        String str = null;
        List<String> arr;

        for (int step = 1; step * 2 <= s.length(); step++) {
            str = s;
            arr =new ArrayList<>();
            while(str.length() >= step){
                arr.add(str.substring(0,step));
                str= str.substring(step);
            }
            if(str.length() > 0) arr.add(str);
            int count = 1;
            StringBuilder builder = new StringBuilder();
     
            for (int j = 1; j <= arr.size(); j++) {
                if(arr.size() == j || !arr.get(j-1).equals(arr.get(j))) {
                    if(count != 1) builder.append(String.valueOf(count));
                    builder.append(arr.get(j-1));
                    count = 1;
                }
                else count++;
            }
            answer = Math.min(builder.toString().length(),answer);
        }
        return answer == Integer.MAX_VALUE ? 1 : answer;
    }

}