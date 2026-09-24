#ifndef ITEM_H
#define ITEM_H

#define MAX_ITEMS 50
#define NAME_LEN 20

struct Item {
    int id;
    char name[NAME_LEN];
    char category[10];
    int qty;
    float price;
};

extern Item items[MAX_ITEMS];
extern int itemCount;

void addItem(const char* name, const char* category, int qty, float price);
void removeItem(int id);
Item* findItem(int id);
void printItems();
void printLowStock(int limit);

#endif
