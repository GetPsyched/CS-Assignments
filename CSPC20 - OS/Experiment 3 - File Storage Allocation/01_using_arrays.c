#include <stdio.h>

void
main() {
    char name[10][30];
    int start[10], size[10], n;
    printf("Enter the number of files to be allocated --> ");
    scanf("%d", &n);

    int count = 0, k, j;
    for (int i = 0; i < n; i++) {
        printf("\nFile #%d:\n", i + 1);
        printf("Name --> "); scanf("%s", &name[i][0]);
        printf("Start block --> "); scanf("%d", &start[i]);
        printf("Number of blocks --> "); scanf("%d", &size[i]);

        for (j = 0, k = 1; j < n && k < n; j++, k++)
            if (!(start[j+1] <= start[j] || start[j+1] >= size[j]))
                count++;

        if (count == 1)
            printf("%s cannot be allocated disk space\n", name[i]);
    }

    printf("\nFile Allocation Table\n");
    printf("%s%40s%40s\n", "File Name", "Start Block", "Length");
    printf("%s%50d%50d\n", name[0], start[0], size[0]);

    for (int i = 0, j = 1; i < n && j < n; i++, j++)
        if (start[i+1] <= start[i] || start[i+1] >= size[i])
            printf("%s%50d%50d\n", name[j], start[j], size[j]);
}
