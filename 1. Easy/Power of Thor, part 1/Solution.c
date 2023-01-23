#include <stdio.h>

int main()
{
    int X, Y, TX, TY;
    scanf("%d%d%d%d", &X, &Y, &TX, &TY);

    while (1) {
        if      (TY < Y) TY++ , printf("S");
        else if (TY > Y) TY-- , printf("N");
        if      (TX < X) TX++ , printf("E");
        else if (TX > X) TX-- , printf("W");
        printf("\n");
    }
}