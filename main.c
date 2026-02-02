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

void searchProductByName() {
    char productName[50];
    printf("Zadejte název produktu: ");
    scanf("%s", productName);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(warehouse[i].name, productName) == 0) {
            printf("Nalezeno: Index %d, Cena %.2f, Kusu %d\n", i, warehouse[i].price, warehouse[i].quantity);
        }
        else {
            printf("Produkt nenalezen!\n");
        }
    }
}
void searchProductByPrice() {
    float min, max;
    printf("Zadejte cenu produktu: ");
    scanf("%f %f", &min, &max);

    for (int i = 0; i < productCount; i++) {
        if (warehouse[i].price >= min && warehouse[i].price <= max) {
            printf("Nalezeno: Index %d, Cena %.2f, Kusu %d\n", i, warehouse[i].price);
        }
        else {
            printf("Produkt nenalezen!\n");
        }
    }
}

void productDetails() {
    int id;
    listAll();
    printf("Zadejte ID produktu: ");
    scanf("%d", &id);

    if (id >= 0 && id < productCount) {
        printf("Nazev: %s\n", warehouse[id].name);
        printf("Cena: %.2f\n", warehouse[id].price);
        printf("Pocet: %d\n", warehouse[id].quantity);
    }
    else {
        printf("Chybné ID!\n");
    }
}
void deleteProduct() {
    int id;
    listAll();
    printf("Zadejte ID produktu pro smazani: ");
    scanf("%d", &id);

    if (id >= 0 && id < productCount) {
        for (int i = id; i < productCount - 1; i++) {
            warehouse[i] = warehouse[i + 1];
        }
        productCount--;
        printf("Smazano.\n");
    }
}

void editProduct() {
    int id;
    listAll();
    printf("Zadej index pro upravu: ");
    scanf("%d", &id);

    if (id >= 0 && id < productCount) {
        printf("Zadej novou cenu: ");
        scanf("%f", &warehouse[id].price);
        printf("Zadej novou sklad: ");
        scanf("%d", &warehouse[id].quantity);
        printf("Upraveno.\n");
    }
}





int main() {
    addProduct("Ipad", 599.99, 322);
    addProduct("MacBook M5", 2999.97, 67;
    addProduct("Airpods Pro 3", 300.00, 41);

    char choice;
    int running = 1;

    while (running == 1) {
        printf("\n1. Vypis\n2. Hledat nazev\n3. Hledat cena\n4. Detail\n5. Smazat\n6. Upravit\n7. Pridat novy\n0. Konec\n");
    }
}