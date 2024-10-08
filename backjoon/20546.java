import java.io.*;
import java.util.*;

class Main {
    // 돈, 주식 수
    public static class Person {
        public int balance;
        public int count;

        public Person(int balance, int count) {
            this.balance = balance;
            this.count = count;
        }
        public void buyAll(int cost){
            this.count += this.balance / cost;
            this.balance = this.balance % cost;
        }
        public void sellAll(int cost){
            this.balance += this.count * cost;
            this.count = 0;
        }
    }

    // 성민: 전량 매도, 전량 매수
    // 3일 연속 상승 및 하락세일때 전량 매도수를 한다.
    // 1월 14일에 더 많은 자산을 보유한 사람이 승리
    private static int[] cost = new int[15];
    private static Person jun; // BNP
    private static Person sung; // TIMING
    private static int change = 0; // 변동
    private static int previousCost;

    public static void main(String[] args) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));
        int initBalance = Integer.parseInt(br.readLine());
        var st = new StringTokenizer(br.readLine());

        jun = new Person(initBalance, 0);
        sung = new Person(initBalance, 0);

        for (int i = 1; i <= 14; i++) {
            cost[i] = Integer.parseInt(st.nextToken()); // 주식 가격
        }

        cost[0] = cost[1];

        for (int i = 1; i < 14; i++) {
            if (jun.balance >= cost[i]) {
                jun.buyAll(cost[i]);
            }

            if (cost[i] - cost[i - 1] > 0) {
                change = change < 0 ? 1 : change + 1;
            } else if (cost[i] - cost[i - 1] < 0) {
                change = change > 0 ? -1 : change - 1;
            } else {
                change = 0;
            }

            if (change <= -3) {
                sung.buyAll(cost[i]);
            } else if (change >= 3) {
                sung.sellAll(cost[i]);
            }
        }

        // 비교
        sung.sellAll(cost[14]);
        jun.sellAll(cost[14]);

        if (sung.balance > jun.balance) {
            System.out.println("TIMING");
        } else if (jun.balance > sung.balance) {
            System.out.println("BNP");
        } else {
            System.out.println("SAMESAME");
        }
    }
}