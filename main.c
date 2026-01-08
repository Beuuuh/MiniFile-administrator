#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HasFiles() {
    //TODO: dinamizar para qualquer pasta
    system("dir /b C:\\Users\\USER\\Desktop\\MiniFile-administrator\\MiniFile-administrator\\output\\teste > temp.txt");
    FILE *f;
    int found = 0;
    char line[256];
    
    f = fopen("temp.txt", "r");

    if (f == NULL) {
        remove("temp.txt");
        return 0;
    }

    if (fgets(line, sizeof(line), f) != NULL) {
        found = 1;
    }

    fclose(f);
    remove("temp.txt");
    return found;
}

int main() {
    int a = HasFiles();
    printf("if theres something in the directory it will show 1");
    printf("\n%d", a);
}