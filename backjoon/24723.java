import java.util.Scanner;

public class Main {
    static int[] arr = {2, 4,8,16,32};

    public static int factorial(int n){
        return arr[n-1];
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(factorial(n));

    }
}
