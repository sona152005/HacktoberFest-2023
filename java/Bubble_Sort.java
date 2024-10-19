// modified this code
public class BubbleSort {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false; // Track if a swap occurred
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    // Swap
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swapped = true; // Set flag to true
                }
            }
            if (!swapped) break; // If no swaps, array is sorted
        }
        return nums;
    }

    public static void main(String[] args) {
        BubbleSort sorter = new BubbleSort();
        int[] nums = {64, 34, 25, 12, 22, 11, 90};
        int[] sortedArray = sorter.sortArray(nums);
        
        System.out.println("Sorted array: ");
        for (int num : sortedArray) {
            System.out.print(num + " ");
        }
    }
}
