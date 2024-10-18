//code modified
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of the shortest common supersequence
int shortestCommonSupersequenceLength(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];

    // Build the DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) 
                dp[i][j] = j; // If X is empty, we need all characters of Y
            else if (j == 0) 
                dp[i][j] = i; // If Y is empty, we need all characters of X
            else if (X[i - 1] == Y[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match
            else 
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]); // Take the minimum
        }
    }

    return dp[m][n];
}

// Function to print the shortest common supersequence
void printSCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1];

    // Rebuild the DP table for SCS
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) 
                dp[i][j] = j;
            else if (j == 0) 
                dp[i][j] = i;
            else if (X[i - 1] == Y[j - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Create SCS string
    int SCSLength = dp[m][n];
    char SCS[SCSLength + 1];
    SCS[SCSLength] = '\0'; // Null terminate the string

    int i = m, j = n, k = SCSLength;
    
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            SCS[k - 1] = X[i - 1];
            i--; j--; k--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            SCS[k - 1] = X[i - 1];
            i--; k--;
        } else {
            SCS[k - 1] = Y[j - 1];
            j--; k--;
        }
    }

    while (i > 0) {
        SCS[k - 1] = X[i - 1];
        i--; k--;
    }

    while (j > 0) {
        SCS[k - 1] = Y[j - 1];
        j--; k--;
    }

    printf("Shortest Common Supersequence: %s\n", SCS);
}

int main() {
    char X[100], Y[100];
    char choice;

    do {
        printf("Enter first string:");
        scanf("%s", X);
        printf("Enter second string:");
        scanf("%s", Y);

        int SCSLength = shortestCommonSupersequenceLength(X, Y);
        printf("Length of Shortest Common Supersequence:%d\n", SCSLength);
        printSCS(X, Y);

        printf("Do you want to find SCS for another pair of strings? (y/n):");
        scanf(" %c", &choice); // Note the space before %c to consume any newline character
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
