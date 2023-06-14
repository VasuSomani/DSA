#include <stdio.h>
#include <string.h>

int main()
{
    char str[32];

    int i = 0;
    int j = 0;
    int l1 = 0;
    int l2 = 0;

    int ind = 0;
    int start = 0;

    printf("Enter string: ");
    scanf("%s", str);

    l1 = strlen(str);

    printf("Enter length: ");
    scanf("%d", &l2);

    printf("The possible subsets are:\n");

    for (i = 1; i <= l1; i++) {
        if (ind - start + 1 == i) {
            if (i == l2) {
                for (j = ind; j < l1; j++) {
                    for (i = start; i < ind; i++)
                        printf("%c", str[i]);
                    printf("%c\n", str[j]);
                }

                if (start != i) {
                    start++;
                    ind = start;
                }
            }
            else
                ind++;
        }
    }

    return 0;
}