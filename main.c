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

    f = fopen("temp.txt", "w");

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

int main() {
    int choice;

    do {
        printf("Mini File Administrator\n");
        printf("Choose your option:\n");

        if(HasFiles(".") == 1) {
            printf("1.Go to another directory 2.Delete directory 3.Rename directory 4.Create text file 5.Rename text file 6.Edit text file 7.Delete text file: ");
        }
        
        scanf("%d", &choice);
    } while(choice <= 7 && choice >= 1);
}