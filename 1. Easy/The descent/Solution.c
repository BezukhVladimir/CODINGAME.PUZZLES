int main() {    int height, index;  
    while (1) { int max_height = 0;
        for (int i = 0; i < 8; i++)  {
            scanf("%d", &height);
            if (height > max_height) {
                max_height = height; index = i; }}
        printf("%d\n", index);}}