#include <stdio.h>

int main() {
    printf("Synchronizing files...\n");

    FILE *src = fopen("source.txt", "r");
    FILE *dst = fopen("backup.txt", "w");

    if (src == NULL || dst == NULL) {
        printf("Cannot open files.\n");
        return 1;
    }

    char ch;

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dst);

    fclose(src);
    fclose(dst);

    printf("Synchronization complete. \n");

    return 0;
}
