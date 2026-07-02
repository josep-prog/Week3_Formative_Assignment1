#include <stdio.h>

int main() {
    FILE *source, *backup, *log;
    char ch;

    log = fopen("backup.log", "w");
    fprintf(log, "Backup started\n");

    source = fopen("source.txt", "r");
    backup = fopen("backup.txt", "w");

    if (source == NULL || backup == NULL) {
        fprintf(log, "Error opening files\n");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
        fputc(ch, backup);

    fprintf(log, "Backup completed\n");

    fclose(source);
    fclose(backup);
    fclose(log);

    return 0;
}
