#include <stdio.h>

unsigned int h, w;
char g[30][30];

int bomb(unsigned int i, unsigned int j) {
    return i < h && j < w && g[i][j]=='x';
}

int count(unsigned i, unsigned int j)
{
    if (bomb(i, j)) return '.';

    int c = bomb(i - 1, j - 1) + bomb(i - 1, j) + bomb(i - 1, j + 1)
          + bomb(i,     j - 1) +                  bomb(i,     j + 1)
          + bomb(i + 1, j - 1) + bomb(i + 1, j) + bomb(i + 1, j + 1);
    return c ? c + '0' : '.';
}

int main()
{
    scanf("%d%d", &w, &h);
    for (int i = 0; i < h; ++i)
        scanf("%s", g + i);
 
    for (int i = 0 ; i < h; ++i) {
        for (int j = 0 ; j < w; ++j)
            putchar(count(i, j));
        putchar('\n');
    }
}