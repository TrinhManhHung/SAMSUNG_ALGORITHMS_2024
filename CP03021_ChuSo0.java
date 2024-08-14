import java.util.Scanner;

public class CP03021_ChuSo0 {
    public static long bac(long n, int k){
        long res = 0;
        while(n != 0){
            res += n / k;
            n /= k;
        }
        return res;
    }
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int test = sc.nextInt();
        while(test != 0){
            long n = sc.nextLong();
            long ans = 0;
            long left = 0, right = 5 * n;
            while(left <= right){
                long mid = (left + right) / 2;
                if(bac(mid, 5) >= n){
                    ans = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            System.out.println(ans);
            test--;
        }
    }
}