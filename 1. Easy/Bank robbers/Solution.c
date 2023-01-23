#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int min_element(int * a, int n) {
    int min = 2147483647, min_i = 0;  

    for (int i = 0; i < n; ++i)
        if (min > a[i]) {
            min = a[i]; min_i = i; }

    return min_i;
}

int max_element(int * a, int n) {
    int max = 0, max_i = 0;  

    for (int i = 0; i < n; i++)
        if (max < a[i]) {
            max = a[i]; max_i = i; }

    return max_i;
}

int main() {
    int R, V;
    int robbers[5] = {0, 0, 0, 0, 0};
    scanf("%d%d", &R, &V);

    for (int i = 0; i < V; i++) {
        int C, N;
        scanf("%d%d", &C, &N);
        robbers[min_element(robbers, R)] += 
            pow(10, N) * pow(5, C - N);
    }

    printf("%d", robbers[max_element(robbers, R)]);
}