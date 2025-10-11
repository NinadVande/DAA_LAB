#include <stdio.h>
#include <string.h>
#define MAX 100
void LRS(char a[])
{
    int n = strlen(a);
    int c[MAX][MAX];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)

                c[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == a[j - 1] && i != j)
            {
                c[i][j] = 1 + c[i - 1][j - 1];
            }
            else
            {
                c[i][j] = (c[i - 1][j] > c[i][j - 1]) ? c[i - 1][j] : c[i][j - 1];
            }
        }
    }
    int lrsLength = c[n][n];
    printf("Length of LRS = %d\n", lrsLength);
    char lrs[MAX];
    int index = lrsLength;
    lrs[index] = '\0';
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == a[j - 1] && i != j)
        {
            lrs[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }
        else if (c[i - 1][j] > c[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("Longest Repeated Subsequence = %s\n", lrs);
}
int main()
{
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    LRS(str);
    return 0;
}


