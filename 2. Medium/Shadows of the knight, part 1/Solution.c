#include <stdio.h>

int main()
{
    int xEnd, yEnd, NUMBER_OF_JUMPS, x, y, x0 = 0, y0 = 0;
    scanf("%d%d%d%d%d", &xEnd, &yEnd, &NUMBER_OF_JUMPS, &x, &y);

    while (1) {
        char message[3];
        scanf("%s", message);
        
        for (int i = 0; i != 2; ++i) {
            if      (message[i] == 'R') x0 = x;
            else if (message[i] == 'D') y0 = y;
            else if (message[i] == 'L') xEnd = x;
            else if (message[i] == 'U') yEnd = y;               
        }
        
        x = (x0 + xEnd) >> 1;
        y = (y0 + yEnd) >> 1;
        
        printf("%d %d\n", x, y);
    }
}