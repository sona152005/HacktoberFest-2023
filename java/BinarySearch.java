// add features in binarysearch
import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        
        System.out.println("Enter the elements (sorted):");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);
        System.out.print("Enter the number to search: ");
        int num = sc.nextInt();

        long startTime = System.nanoTime();
        int index = binarySearch(arr, num);
        long endTime = System.nanoTime();

        if (index != -1) {
            System.out.println("Found at position: " + (index + 1));
        } else {
            System.out.println("Number not found.");
        }

        System.out.println("Time taken: " + (endTime - startTime) + " ns");
        sc.close();
    }

    static int binarySearch(int[] arr, int num) {
        int low = 0, high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == num) {
                return mid; 
            } else if (arr[mid] < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; 
    }
}
