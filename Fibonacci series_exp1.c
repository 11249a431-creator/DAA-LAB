#include <stdio.h>
int main()
{
    int n, i = 3;
    int first = 0, second = 1, next;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if (n >= 1)
        printf("%d ", first);
    if (n >= 2)
        printf("%d ", second);
    while (i <= n)
    {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
        i++;
    }
    return 0;
}

