import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    /** A
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int count = 0;
        int n = Integer.parseInt(st.nextToken());
        for(int i = 0 ; i< n ;i++){
            st = new StringTokenizer(br.readLine(),"D-");

            if(Integer.parseInt(st.nextToken()) <= 90){
                count++;
            }
        }
        System.out.println(count);

    }
     */
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int count = 0;
        int n = Integer.parseInt(st.nextToken());
        HashMap<String ,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String f_m = st.nextToken(), s_m = st.nextToken();
            if(map.getOrDefault(f_m,0) == 1 || map.getOrDefault(s_m,0) == 1){
                map.put(s_m, 1);
                map.put(f_m, 1);
            }
            // 총총을 만났다면
            if (f_m.equals("ChongChong") || s_m.equals("ChongChong")) {
                map.put(s_m,1);
                map.put(f_m,1);
            }
        }
        for (String s : map.keySet()) {
            if(map.getOrDefault(s,0) == 1)
                count++;
        }
        System.out.println(count == 0 ? 1 : count);

    }

    /** C
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long total = 0;
        long[] gom = new long[3];
        gom[0] = Long.parseLong(st.nextToken());
        gom[1] = Long.parseLong(st.nextToken());
        gom[2] = Long.parseLong(st.nextToken());
        total = gom[0] + gom[1]+ gom[2];
        st = new StringTokenizer(br.readLine());
        long[] t = new long[3];
        t[0] = Long.parseLong(st.nextToken());
        t[1] = Long.parseLong(st.nextToken());
        t[2] = Long.parseLong(st.nextToken());

        for(int j = 0 ; j < 3; j++)
            for(int i =  0 ; i< 3; i++){
            long cal = gom[i % 3] - t[i % 3];
            gom[i % 3] = cal < 0 ? 0 : cal;
            t[i % 3] = cal >= 0 ? 0 : Math.abs(cal);
            if(t[i%3] >=3 ){
                long pause_t = t[i]/3;
                t[(i+1) %3] += pause_t;
                t[i%3] -= pause_t * 3;
            }
        }

        for(int i = 0 ; i < 3; i++){
            total -= gom[i];
        }
        System.out.println(total);
    }
*/
    /** D */
}