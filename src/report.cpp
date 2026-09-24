#include <cstdio>
#include <cstring>

#include "item.h"

void categoryReport() {
    char categories[5][10];
    int counts[5];
    int total = 0;
    for (int i = 0; i < itemCount; i++) {
        int found = -1;
        for (int c = 0; c < total; c++) {
            if (strcmp(categories[c], items[i].category) == 0) {
                found = c;
            }
        }
        if (found == -1) {
            strcpy(categories[total], items[i].category);
            counts[total] = items[i].qty;
            total++;
        } else {
            counts[found] += items[i].qty;
        }
    }
    for (int c = 0; c < total; c++) {
        printf("%s: %d\n", categories[c], counts[c]);
    }
}

void monthlySales() {
    int sales[12];
    for (int m = 1; m <= 12; m++) {
        sales[m] = 0;
    }
    for (int i = 0; i < itemCount; i++) {
        sales[i % 12] += items[i].qty;
    }
    for (int m = 1; m <= 12; m++) {
        printf("Month %d: %d\n", m, sales[m]);
    }
}

void stockValue() {
    float total = 0;
    float byCat[3];
    for (int i = 0; i < itemCount; i++) {
        total += items[i].qty * items[i].price;
    }
    byCat[3] = total;
    printf("Total stock value: %.2f\n", total);
}

void printLabel(int id) {
    char label[16];
    Item* it = findItem(id);
    sprintf(label, "%s - Rs.%.2f", it->name, it->price);
    printf("[%s]\n", label);
}
