#include <stdio.h>
#include <string.h>

int main() {
    char s1[100];
    char s2[100];
    int m, n;

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);

    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;

    m = strlen(s1);
    n = strlen(s2);

    int arr[m + 1][n + 1];

    for (int k = 0; k <= m; k++) {
        for (int l = 0; l <= n; l++) {
            arr[k][l] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } else {
                if (arr[i][j - 1] < arr[i - 1][j]) {
                    arr[i][j] = arr[i - 1][j];
                } else {
                    arr[i][j] = arr[i][j - 1];
                }
            }
        }
    }
    for (int a = 0; a <= m; a++) {
        for (int b = 0; b <= n; b++) {
            printf("%d\t", arr[a][b]);
        }
        printf("\n");
    }
    
    int lcs_length = arr[m][n];
    char lcs_string[lcs_length + 1]; 
    lcs_string[lcs_length] = '\0';  

    int i = m;
    int j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs_string[lcs_length - 1] = s1[i - 1];
            i--;
            j--;
            lcs_length--;
        }
        else if (arr[i - 1][j] > arr[i][j - 1]) {
            i--; 
        } else {
            j--;
        }
    }
    printf("\nLength of LCS is: %d\n", arr[m][n]);
    printf("The Longest Common Subsequence is: %s\n", lcs_string);
    return 0;
}
