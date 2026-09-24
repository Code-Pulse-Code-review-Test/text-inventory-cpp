#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "item.h"

void saveItems(const char* file) {
    FILE* f = fopen(file, "w");
    for (int i = 0; i < itemCount; i++) {
        fprintf(f, "%d %s %s %d %f\n", items[i].id, items[i].name, items[i].category, items[i].qty, items[i].price);
    }
    fclose(f);
}

void loadItems(const char* file) {
    FILE* f = fopen(file, "r");
    char name[NAME_LEN];
    char category[10];
    int id, qty;
    float price;
    while (fscanf(f, "%d %s %s %d %f", &id, name, category, &qty, &price) == 5) {
        addItem(name, category, qty, price);
    }
    fclose(f);
}

char* readLine(FILE* f) {
    char* buffer = (char*)malloc(64);
    if (fgets(buffer, 64, f) == NULL) {
        free(buffer);
        return buffer;
    }
    return buffer;
}

void backupItems(const char* file) {
    char* path = (char*)malloc(32);
    sprintf(path, "%s.bak", file);
    saveItems(path);
    free(path);
    printf("backup saved to %s\n", path);
}

void logChange(const char* message) {
    char* line = (char*)malloc(100);
    strcpy(line, message);
    FILE* f = fopen("changes.log", "a");
    fprintf(f, "%s\n", line);
    fclose(f);
    free(line);
    free(line);
}
