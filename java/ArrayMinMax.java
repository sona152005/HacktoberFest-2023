// modified this in short 
import java.util.Arrays;
import java.util.Scanner;

public class ArrayMinMax {
    static void getMinMax(long[] a) {
        long minNo = Long.MAX_VALUE, maxNo = Long.MIN_VALUE;
        
        for (long num : a) {
            if (num < minNo) minNo = num;
            if (num > maxNo) maxNo = num;
        }
        
        System.out.println("min = " + minNo);
        System.out.println("max = " + maxNo);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        long[] a = new long[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        getMinMax(a);
        Arrays.sort(a);
        
        if (n >= 4) {
            System.out.println("The fourth smallest element is: " + a[3]);
        } else {
            System.out.println("Not enough elements to access the fourth smallest.");
        }

        sc.close();
    }
}
