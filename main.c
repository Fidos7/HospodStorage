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

// funcs

void listAll() {
    printf("\n==========================================================\n");
    printf("| %-5s | %-20s | %-10s | %-8s |\n", "ID", "NAZEV PRODUKTU", "CENA", "SKLADEM");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        printf("| %-5d | %-20s | %-10.2f | %-8d |\n",
               i, warehouse[i].name, warehouse[i].price, warehouse[i].quantity);
    }
    printf("==========================================================\n");

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
    int found = 0;
    printf("Zadejte nazev produktu: ");
    scanf("%s", productName);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(warehouse[i].name, productName) == 0) {
            printf("Nalezeno: Index %d, Cena %.2f, Kusu %d\n", i, warehouse[i].price, warehouse[i].quantity);
            found = 1;
        }
    }
    if (!found) printf("Produkt nenalezen!\n");
}

void searchProductByPrice() {
    float min, max;
    int found = 0;
    printf("Zadejte rozmezi ceny (min max): ");
    scanf("%f %f", &min, &max);

    for (int i = 0; i < productCount; i++) {
        if (warehouse[i].price >= min && warehouse[i].price <= max) {
            printf("Nalezeno: %s, Cena %.2f, Kusu %d\n", warehouse[i].name, warehouse[i].price, warehouse[i].quantity);
            found = 1;
        }
    }
    if (!found) printf("V teto cenove hladine nic nemame.\n");
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
    } else {
        printf("Chybne ID!\n");
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
    } else {
        printf("Chybne ID!\n");
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
        printf("Zadej novy pocet kusu: ");
        scanf("%d", &warehouse[id].quantity);
        printf("Upraveno.\n");
    } else {
        printf("Neplatny index!\n");
    }
}

int main() {

    addProduct("Ipad", 599.99, 322);
    addProduct("MacBook", 2999.97, 67);
    addProduct("Airpods", 300.00, 41);

    char choice;
    int running = 1;

    while (running == 1) {
        printf("\n1. Vypis\n2. Hledat nazev\n3. Hledat cena\n4. Detail\n5. Smazat\n6. Upravit\n7. Pridat novy\nX. Konec\n");
        printf("Volba: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': listAll(); break;
            case '2': searchProductByName(); break;
            case '3': searchProductByPrice(); break;
            case '4': productDetails(); break;
            case '5': deleteProduct(); break;
            case '6': editProduct(); break;
            case '7': {
                char n[50]; float p; int q;
                printf("Nazev: "); scanf("%s", n);
                printf("Cena: "); scanf("%f", &p);
                printf("Pocet: "); scanf("%d", &q);
                addProduct(n, p, q);
                break;
            }
            case 'x':
            case 'X':
                printf("Ukoncuji program...\n");
                running = 0;
                break;
            default:
                printf("Neplatna volba!\n");
        }
    }
    return 0;
}