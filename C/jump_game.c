// modified code in short and add some features
#include <stdio.h>
#include <stdbool.h>

bool canJump(int *nums, int numsSize) {
    int maxReach = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > maxReach) return false; 

        maxReach = (i + nums[i] > maxReach) ? (i + nums[i]) : maxReach;

        printf("Index: %d, Max Reach: %d\n", i, maxReach);  
        if (maxReach >= numsSize - 1) return true; 
    }

    return false;
}

int main() {
    int nums[100], numsSize;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    if (canJump(nums, numsSize)) {
        printf("Yes, you can reach the end of the array!\n");
    } else {
        printf("No, you cannot reach the end of the array.\n");
    }

    return 0;
}
