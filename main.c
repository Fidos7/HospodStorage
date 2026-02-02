#include <stdio.h>
#include <string.h>


// struktury
struct Product {
    char name[50];
    float price;
    int quantity;
};


struct Product warehouse[10];
int productCount = 0;


// func

void listAll() {
    printf("\n==========================================================\n");
    printf("| %-5s | %-20s | %-10s | %-8s |\n", "ID", "NAZEV PRODUKTU", "CENA", "SKLADEM");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        printf("| %-5d | %-20s | %-10.2f | %-8d |\n",
               i,
               warehouse[i].name,
               warehouse[i].price,
               warehouse[i].quantity);
    }
    printf("==========================================================\n");

    // celkova hgodnota skladu, bonus
    float total = 0;
    for (int i = 0; i < productCount; i++) {
        total += warehouse[i].price * warehouse[i].quantity;
    }
    printf(" Celkova hodnota skladu: %.2f Kc\n", total);
    printf("==========================================================\n");
}

void addProduct(char* n, float p, int q) {
    if (productCount < 10) {
        strcpy(warehouse[productCount].name, n);
        warehouse[productCount].price = p;
        warehouse[productCount].quantity = q;
        productCount++;
    } else {
        printf("Sklad je plny!\n");
    }
}
int main() {
    return 0;
}