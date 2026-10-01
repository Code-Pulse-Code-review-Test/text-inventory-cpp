#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "item.h"

void saveItems(const char* file) {
    FILE* f = fopen(file, "w");
    if (f == NULL) {
        printf("could not open %s\n", file);
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        fprintf(f, "%d %s %s %d %f\n", items[i].id, items[i].name, items[i].category, items[i].qty, items[i].price);
    }
    fclose(f);
}

void loadItems(const char* file) {
    FILE* f = fopen(file, "r");
    if (f == NULL) {
        printf("could not open %s\n", file);
        return;
    }
    char name[NAME_LEN];
    char category[10];
    int id, qty;
    float price;
    while (fscanf(f, "%d %19s %9s %d %f", &id, name, category, &qty, &price) == 5) {
        addItem(name, category, qty, price);
    }
    fclose(f);
}

char* readLine(FILE* f) {
    char* buffer = (char*)malloc(64);
    if (fgets(buffer, 64, f) == NULL) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

void backupItems(const char* file) {
    char path[256];
    snprintf(path, sizeof(path), "%s.bak", file);
    saveItems(path);
    printf("backup saved to %s\n", path);
}

void logChange(const char* message) {
    FILE* f = fopen("changes.log", "a");
    if (f == NULL) {
        return;
    }
    fprintf(f, "%s\n", message);
    fclose(f);
}
