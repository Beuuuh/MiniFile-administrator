#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HasFiles(char directory[256]) {
    char command[256];
    char line[256];
    int found = 0;
    FILE *f;

    sprintf(command, "dir /b %s > temp.txt", directory);
    system(command);

    f = fopen("temp.txt", "r");

    if(f == NULL) {
        remove("temp.txt");
        return 0;
    }

    if(fgets(line, sizeof(line), f) != NULL) {
        found = 1;
    }

    fclose(f);
    remove("temp.txt");
    return found;
}

void gotoDirectory(char directory[256]) {
    char command[256];
    sprintf(command, "cd  %s", directory);
    system(command);
}

int main() {
    int choice;

    printf("Mini File Administrator\n");
    printf("Choose your option:\n");

    if(HasFiles(".") == 1) {
        printf("1.Create directory 2.Go to another directory 3.Delete directory 4.Rename directory 5.Create text file 6.Rename text file 7.Edit text file 8.Delete text file: ");
        
        do {
            system("cls");
            printf("1.Create directory 2.Go to another directory 3.Delete directory 4.Rename directory 5.Create text file 6.Rename text file 7.Edit text file 8.Delete text file: ");
            scanf("%d", &choice);
        } while(choice <= 8 && choice >= 1);
    } else {
        printf("1.Create directory 2.Create text file: ");

        do {
            system("cls");
            printf("1.Create directory 2.Create text file: ");
            scanf("%d", &choice);
        } while(choice != 1 || choice != 2);
}