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

    printf("File\tstart\tsize\tblock\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].name, f[i].start, f[i].size);
        for (j = 0; j < f[i].size; j++)
            printf("%d ", f[i].block[j]);
        printf("%d", f[i].block[j]);
        printf("\n");
    }
}
