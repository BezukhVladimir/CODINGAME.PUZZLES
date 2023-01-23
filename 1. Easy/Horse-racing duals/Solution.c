#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp (const void *a, const void *b) { return (*(int*)a - *(int*)b); }

int main()
{
    int N, max;
    scanf("%d", &N);
    int horses[N];

    for (int i = 0; i < N; ++i) {
        scanf("%d", &horses[i]);
    }

    qsort(horses, N, sizeof(int), cmp);

    max = horses[1] - horses[0];
    for(int i = 2; i < N; ++i) 
        if((horses[i] - horses[i - 1]) <max)
            max = horses[i] - horses[i - 1];

    printf("%d\n",max);
}