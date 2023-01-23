#include <stdio.h>
#include <string.h>

int W, H; 
char font[100][100 * 20 + 1];

int mayanGetOne() {
    char line[H][W + 1];
    for (int i = 0; i < H; ++i)
        scanf("%s", line[i]);

    int result;
    for (result = 0; result < 20; ++result) {
        int h;
        for (h = 0; h < H; ++h)
            if (memcmp(line[h], &font[h][result * W], W)) 
                break;
        if (h == H) break;
    }

    return result;
}

long MayanGet() {
    int N;
    scanf("%d", &N);
    N /= H;
    long result = 0;
    while (N--) result = 20 * result + mayanGetOne();
    return result;
}

void mayanPut(long a) {
    if (a > 20) mayanPut(a / 20);
    int offset =  W * (a % 20);
    for (int i = 0; i < H ; ++i) 
        printf("%.*s\n", W, font[i] + offset);
}

int main() {
    scanf("%d%d", &W, &H);
    for (int i = 0; i < H; ++i)
        scanf("%s", font[i]);

    long a = MayanGet();
    long b = MayanGet();

    char op[2];
    scanf("%s", &op);  
    switch (*op) {
        case '+' : a += b ; break;
        case '*' : a *= b ; break;
        case '-' : a -= b ; break;
        case '/' : a /= b ; break;
    }

    mayanPut(a);
}