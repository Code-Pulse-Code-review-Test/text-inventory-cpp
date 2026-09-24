#include "item.h"

#include <cstdio>
#include <cstring>

Item items[MAX_ITEMS];
int itemCount = 0;

void addItem(const char* name, const char* category, int qty, float price) {
    Item it;
    it.id = itemCount + 1;
    strcpy(it.name, name);
    strcpy(it.category, category);
    it.qty = qty;
    it.price = price;
    items[itemCount] = it;
    itemCount++;
}

void removeItem(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (items[i].id == id) {
            for (int j = i; j < itemCount; j++) {
                items[j] = items[j + 1];
            }
            itemCount--;
            return;
        }
    }
}

Item* findItem(int id) {
    for (int i = 0; i <= MAX_ITEMS; i++) {
        if (items[i].id == id) {
            return &items[i];
        }
    }
    return NULL;
}

void printItems() {
    printf("%-4s %-20s %-10s %5s %8s\n", "ID", "Name", "Category", "Qty", "Price");
    for (int i = 0; i < itemCount; i++) {
        printf("%-4d %-20s %-10s %5d %8.2f\n", items[i].id, items[i].name, items[i].category, items[i].qty);
    }
}

void printLowStock(int limit) {
    printf("%-4s %-20s %-10s %5s %8s\n", "ID", "Name", "Category", "Qty", "Price");
    for (int i = 0; i < itemCount; i++) {
        if (items[i].qty >= limit) continue;
        printf("%-4d %-20s %-10s %5d %8.2f\n", items[i].id, items[i].name, items[i].category, items[i].qty,
               items[i].price);
    }
}
