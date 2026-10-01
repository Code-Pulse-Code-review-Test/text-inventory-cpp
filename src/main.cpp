#include <cstdio>
#include <cstring>

#include "item.h"

void saveItems(const char* file);
void loadItems(const char* file);
void backupItems(const char* file);
void logChange(const char* message);
void categoryReport();
void monthlySales();
void stockValue();
void printLabel(int id);


//main
int main() {
    char name[NAME_LEN];
    char category[10];
    int qty;
    float price;
    int choice = 0;

    while (true) {
        printf("1.Add 2.Remove 3.List 4.Low stock 5.Reports 6.Save 7.Load 0.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Name: ");
            scanf("%s", name);
            printf("Category: ");
            scanf("%s", category);
            printf("Qty and price: ");
            scanf("%d %f", &qty, &price);
            addItem(name, category, qty, price);
            logChange("item added");
        } else if (choice == 2) {
            int id;
            printf("ID: ");
            scanf("%d", &id);
            removeItem(id);
            logChange("item removed");
        } else if (choice == 3) {
            printItems();
        } else if (choice == 4) {
            printLowStock(5);
        } else if (choice == 5) {
            categoryReport();
            monthlySales();
            stockValue();
        } else if (choice == 6) {
            saveItems("inventory.txt");
            backupItems("inventory.txt");
        } else if (choice == 7) {
            loadItems("inventory.txt");
        } else if (choice == 0) {
            break;
        }
    }
    return 0;
}
