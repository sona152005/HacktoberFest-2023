//error clear in this code
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BucketSort {
    public static void bucketSort(float[] arr) {
        int n = arr.length;
        if (n <= 0) return;

        // Create buckets
        List<List<Float>> buckets = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            buckets.add(new ArrayList<>());
        }

        
        for (float num : arr) {
            int bucketIndex = (int) (num * n);
            if (bucketIndex >= n) {
                bucketIndex = n - 1; 
            }
            buckets.get(bucketIndex).add(num);
        }

        
        int index = 0;
        for (List<Float> bucket : buckets) {
            Collections.sort(bucket); 
            for (float num : bucket) {
                arr[index++] = num; 
            }
        }
    }

    public static void main(String[] args) {
        float[] arr = {0.42f, 0.32f, 0.23f, 0.54f, 0.32f, 0.75f, 0.12f, 0.22f};
        System.out.println("Original array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }

        bucketSort(arr);

        System.out.println("\nSorted array:");
        for (float num : arr) {
            System.out.print(num + " ");
        }
    }
}
