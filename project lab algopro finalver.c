#include <stdio.h>
#include <math.h>

typedef struct {
    char name[50];
    long long int quantity;
    long long int price;
} Item;

void foodMenu(long long int *totalPrice, long long int *food_quant, Item *foodItems, int *foodCount) {
    int pickItem_food;
    long long int price_food, buy_quant, total_food;
    char choice_food = 'Y';
    do {
        system("cls");
        printf("1. Bread                5000\n");
        printf("2. Instant rice         20000\n");
        printf("3. Instant noodle       25000\n");
        printf("4. Instant curry        40000\n");
        printf("5. Chips                15000\n");
        printf("6. Chocolate bar        10000\n");
        printf("Choose the food you want: ");
        scanf("%d", &pickItem_food);
        getchar();

        switch (pickItem_food) {
            case 1:
                strcpy(foodItems[*foodCount].name, "Bread");
                price_food = 5000;
                break;
            case 2:
                strcpy(foodItems[*foodCount].name, "Instant rice");
                price_food = 20000;
                break;
            case 3:
                strcpy(foodItems[*foodCount].name, "Instant noodle");
                price_food = 25000;
                break;
            case 4:
            	strcpy(foodItems[*foodCount].name, "Instant curry");
                price_food = 40000;
            	break;
            case 5:
            	strcpy(foodItems[*foodCount].name, "Chips");
                price_food = 15000;
                break;
            case 6:
            	strcpy(foodItems[*foodCount].name, "Chocolate bar");
                price_food = 10000;
                break;
            default:
                printf("The item you have chosen does not exist\n");
                continue;
        }

        printf("Input quantity of item: ");
        scanf("%lld", &buy_quant);
        getchar();

        *food_quant += buy_quant; // Total food quantity
        total_food = buy_quant * price_food;
        *totalPrice += total_food;

        foodItems[*foodCount].quantity = buy_quant;
        foodItems[*foodCount].price = total_food;
        (*foodCount)++;
        
        printf("Item(s) chosen: %lld\n", *food_quant);
        printf("Total price: %lld\n", *totalPrice);
        printf("----------------------------------------------------------------------\n");
        printf("Do you want to add another food?[Y/N]: ");
        scanf(" %c", &choice_food);
        getchar();
    } while (choice_food == 'Y' || choice_food == 'y');
}

void drinkMenu(long long int *totalPrice, long long int *beverage_quant, Item *drinkItems, int *drinkCount) {
    int pickItem_beverage;
    long long int price_beverage, buy_quant, total_beverage;
    char choice_beverage = 'Y';
    do {
        system("cls");
        printf("1. Mineral water         5000\n");
        printf("2. Energy drink          10000\n");
        printf("3. Coffee                15000\n");
        printf("4. Lemon tea             15000\n");
        printf("5. Milk                  13000\n");
        printf("6. Soda                  18000\n");
        printf("Choose the beverage you want: ");
        scanf("%d", &pickItem_beverage);
        getchar();

        switch (pickItem_beverage) {
            case 1:
                strcpy(drinkItems[*drinkCount].name, "Mineral Water");
                price_beverage = 5000;
                break;
            case 2:
                strcpy(drinkItems[*drinkCount].name, "Energy Drink");
                price_beverage = 10000;
                break;
            case 3:
                strcpy(drinkItems[*drinkCount].name, "Coffee");
                price_beverage = 15000;
                break;
            case 4:
            	strcpy(drinkItems[*drinkCount].name, "Lemon tea");
                price_beverage = 15000;
                break;
            case 5:
            	strcpy(drinkItems[*drinkCount].name, "Milk");
                price_beverage = 13000;
                break;
            case 6:
            	strcpy(drinkItems[*drinkCount].name, "Soda");
                price_beverage = 18000;
                break;
            default:
                printf("The item you have chosen does not exist\n");
                continue;
        }

        printf("Input quantity of item: ");
        scanf("%lld", &buy_quant);
        getchar();

        *beverage_quant += buy_quant;
        total_beverage = buy_quant * price_beverage;
        *totalPrice += total_beverage;

        drinkItems[*drinkCount].quantity = buy_quant;
        drinkItems[*drinkCount].price = total_beverage;
        (*drinkCount)++;
        
        printf("Item(s) chosen: %lld\n", *beverage_quant);
        printf("Total price: %lld\n", *totalPrice);
        printf("----------------------------------------------------------------------\n");
        printf("Do you want to add another beverage?[Y/N]: ");
        scanf(" %c", &choice_beverage);
        getchar();
    } while (choice_beverage == 'Y' || choice_beverage == 'y');
}

void bubbleSort(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(items[j].name, items[j + 1].name) > 0) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

void writeToFile(const char *filename, Item foodItems[], int foodCount, Item drinkItems[], int drinkCount, long long int total_items, long long int totalPrice) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(file, "Food:\n");
    fprintf(file, "-----------------------------------------------------------------------------\n");
    fprintf(file, "\n");
    for (int i = 0; i < foodCount; i++) {
        fprintf(file, "%s - Quantity: %lld - Total Price: %lld\n", foodItems[i].name, foodItems[i].quantity, foodItems[i].price);
    }
    fprintf(file, "\n");
    fprintf(file, "Drink:\n");
    fprintf(file, "-----------------------------------------------------------------------------\n");
    fprintf(file, "\n");
    for (int i = 0; i < drinkCount; i++) {
        fprintf(file, "%s - Quantity: %lld - Total Price: %lld\n", drinkItems[i].name, drinkItems[i].quantity, drinkItems[i].price);
    }
    fprintf(file, "-----------------------------------------------------------------------------\n");
    fprintf(file, "Total items: %lld\n", total_items);
    fprintf(file, "Subtotal: %lld\n", totalPrice);
    fprintf(file, "Thank you for shopping at Binus Minimarket!\n");

    fclose(file);
}

int main() {
    long long int totalPrice = 0, food_quant = 0, beverage_quant = 0, total_items;
    char choice_item = 'Y', receipt;
    const char *filename = "receipt.txt";
    Item foodItems[100];
    Item drinkItems[100];
    int foodCount = 0, drinkCount = 0;

    do {
        system("cls");
        printf("Welcome to Binus Minimarket\n");
        printf("----------------------------------------------------------------------\n");
        printf("What kind of items will you be buying today?\n");
        printf("1. Food\n");
        printf("2. Beverage\n");
        printf("Choose a category [1/2]: ");
        int pickCategory;
        scanf("%d", &pickCategory);
        getchar();

        switch (pickCategory) {
            case 1:
                foodMenu(&totalPrice, &food_quant, foodItems, &foodCount);
                break;
            case 2:
                drinkMenu(&totalPrice, &beverage_quant, drinkItems, &drinkCount);
                break;
            default:
                printf("Invalid category chosen. Please choose again.\n");
        }

        printf("Do you want to add another item?[Y/N]: ");
        scanf(" %c", &choice_item);
        getchar();
    } while (choice_item == 'Y' || choice_item == 'y');

    bubbleSort(foodItems, foodCount);
    bubbleSort(drinkItems, drinkCount);

    total_items = food_quant + beverage_quant;

    system("cls");
    printf("Food:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    for (int i = 0; i < foodCount; i++) {
        printf("%s - Quantity: %lld - Total Price: %lld\n", foodItems[i].name, foodItems[i].quantity, foodItems[i].price);
    }
    printf("\n");
    printf("Drink:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("\n");
    for (int i = 0; i < drinkCount; i++) {
        printf("%s - Quantity: %lld - Total Price: %lld\n", drinkItems[i].name, drinkItems[i].quantity, drinkItems[i].price);
    }
    printf("-----------------------------------------------------------------------------\n");
    printf("Total items: %lld\n", total_items);
    printf("Subtotal: %lld\n", totalPrice);
    printf("Do you want the receipt?[Y/N]: ");
    scanf(" %c", &receipt);
    getchar();

    if (receipt == 'Y' || receipt == 'y') {
        writeToFile(filename, foodItems, foodCount, drinkItems, drinkCount, total_items, totalPrice);
        printf("Thank you for shopping at Binus Minimarket!\n");
    } else if (receipt == 'N' || receipt == 'n') {
        printf("Thank you for shopping at Binus Minimarket!\n");
    }

    return 0;
}

