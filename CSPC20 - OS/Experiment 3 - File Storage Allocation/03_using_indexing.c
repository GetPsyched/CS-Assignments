#include <stdio.h>

typedef struct {
    char name[20];
    int start, size, block[10];
} file;

void
main() {
    int j, n;
    printf("Enter the number of files to be allocated --> ");
    scanf("%d", &n);
    file f[n];

    for (int i = 0; i < n; i++) {
        printf("\nFile #%d:\n", i + 1);
        printf("Name --> "); scanf("%s", &f[i].name);
        printf("Start block --> "); scanf("%d", &f[i].start);
        printf("Number of blocks --> "); scanf("%d", &f[i].size);
        printf("Block numbers --> ");
        for (j = 0; j < f[i].size; j++)
            scanf("%d", &f[i].block[j]);
    }

    printf("\nFile\t index\tlength\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, f[i].start, f[i].size);

    char file_name[10];
    printf("\nEnter file name:"); scanf("%s", &file_name);
    int i = (int)file_name[0] - 1;
    printf("\nIndex --> %d", f[i].start);

    for (j = 0; j < f[i].size; j++)
        printf("%3d", f[i].block[j]);
}
