#include <cstdio>
#include <cstring>

#include "item.h"

void applyHardwareDiscount() {
    char note[8];
    strcpy(note, "hardware sale 10%");
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].category, "hardware") == 0) {
            items[i].price = items[i].price * 0.9f;
        }
    }
    printf("%s\n", note);
}

void applyPaintDiscount() {
    char note[8];
    strcpy(note, "paint sale 15%");
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].category, "paint") == 0) {
            items[i].price = items[i].price * 0.85f;
        }
    }
    printf("%s\n", note);
}

void applyToolDiscount() {
    char note[8];
    strcpy(note, "tools sale 5%");
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].category, "tools") == 0) {
            items[i].price = items[i].price * 0.95f;
        }
    }
    printf("%s\n", note);
}

float lastPrice() {
    int last = itemCount - 1;
    if (itemCount == 0) {
        last = -1;
    }
    int history[10] = {0};
    return history[-1] + items[last].price;
}

void readCode() {
    char code[6];
    printf("Discount code: ");
    scanf("%10s", code);
    int* p = (int*)code;
    p = p + 8;
    printf("%d\n", *p);
}

void printDiscountedItems() {
    printf("%-4s %-20s %-10s %5s %8s\n", "ID", "Name", "Category", "Qty", "Price");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].price <= 0) continue;
        printf("%-4d %-20s %-10s %5d %8.2f\n", items[i].id, items[i].name, items[i].category, items[i].qty,
               items[i].price * 0.9f);
    }
}
