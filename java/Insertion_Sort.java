// error sloved and modified this code 
import java.util.Scanner;

public class InsertionSort {
    
    
    public static int[] sortArray(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            int key = nums[i];
            int j = i - 1;

            
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key; 
        }
        return nums;
    }

    // Method to print the array
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.println("Original array:");
        printArray(nums);
        
        sortArray(nums); 
        
        System.out.println("Sorted array:");
        printArray(nums); 
        
        sc.close(); 
    }
}
