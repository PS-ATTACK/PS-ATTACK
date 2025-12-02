import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {

  public static void main(String[] args) throws IOException {
    var br = new BufferedReader(new InputStreamReader(System.in));
    var sb = new StringBuilder();

    for (int t=0;t<3;t++){
      long n =  Long.parseLong(br.readLine());
      BigInteger sum = BigInteger.ZERO;
      for(int i=0;i<n;i++){
        sum = sum.add(BigInteger.valueOf(Long.parseLong(br.readLine())));
      }

      int res = sum.compareTo(BigInteger.ZERO);
      if (res == 0) {
        sb.append("0\n");
      } else if (res == 1) {
        sb.append("+\n");
      } else {
        sb.append("-\n");
      }
    }
    System.out.println(sb);
    br.close();
  }

}