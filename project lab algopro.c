#include <stdio.h>
#include <math.h>

void foodMenu(long long int *totalPrice, long long int *food_quant) {
    int pickItem_food;
    long long int price_food, buy_quant, total_food;
    char choice_food = 'Y';
    do {
        system("cls");
        printf("1. Bread                5000\n");
        printf("2. Rice                 20000\n");
        printf("3. Noodle               25000\n");
        printf("Choose the food you want: ");
        scanf("%d", &pickItem_food);
        getchar();

        switch (pickItem_food) {
            case 1:
                printf("Input quantity of item: ");
                scanf("%lld", &buy_quant);
                getchar();
                *food_quant += buy_quant; // Accumulate total food quantity
                price_food = 5000;
                total_food = buy_quant * price_food;
                break;
            case 2:
                printf("Input quantity of item: ");
                scanf("%lld", &buy_quant);
                getchar();
                *food_quant += buy_quant;
                price_food = 20000;
                total_food = buy_quant * price_food;
                break;
            case 3:
                printf("Input quantity of item: ");
                scanf("%lld", &buy_quant);
                getchar();
                *food_quant += buy_quant;
                price_food = 25000;
                total_food = buy_quant * price_food;
                break;
            default:
                printf("The item you have chosen does not exist\n");
                continue;
        }
        *totalPrice += total_food; // Update cumulative total price
        printf("Item(s) chosen: %lld\n", *food_quant);
        printf("Total price: %lld\n", *totalPrice);
        printf("----------------------------------------------------------------------\n");
        printf("Do you want to add another food?[Y/N]: ");
        scanf(" %c", &choice_food);
        getchar();
    } while (choice_food == 'Y' || choice_food == 'y');
}

void drinkMenu(long long int *totalPrice, long long int *beverage_quant) {
    int pickItem_beverage;
    long long int price_beverage, buy_quant, total_beverage;
    char choice_beverage = 'Y';
    do {
        system("cls");
        printf("1. Mineral water         5000\n");
        printf("2. Energy drink          10000\n");
        printf("3. Coffee                15000\n");
        printf("Choose the beverage you want: ");
        scanf("%d", &pickItem_beverage);
        getchar();

        switch (pickItem_beverage) {
            case 1:
                printf("Input quantity of item: ");
                scanf("%lld", &buy_quant);
                getchar();
                *beverage_quant += buy_quant; // Accumulate total beverage quantity
                price_beverage = 5000;
                total_beverage = buy_quant * price_beverage;
                break;
            case 2:
                printf("Input quantity of item: ");
                scanf("%lld", &buy_quant);
                getchar();
                *beverage_quant += buy_quant;
                price_beverage = 10000;
                total_beverage = buy_quant * price_beverage;
                break;
            case 3:
                printf("Input quantity of item: ");
                scanf("%lld", &buy_quant);
                getchar();
                *beverage_quant += buy_quant;
                price_beverage = 15000;
                total_beverage = buy_quant * price_beverage;
                break;
            default:
                printf("The item you have chosen does not exist\n");
                continue;
        }

        *totalPrice += total_beverage; // Update cumulative total price
        printf("Item(s) chosen: %lld\n", *beverage_quant);
        printf("Total price: %lld\n", *totalPrice);
        printf("----------------------------------------------------------------------\n");
        printf("Do you want to add another beverage?[Y/N]: ");
        scanf(" %c", &choice_beverage);
        getchar();
    } while (choice_beverage == 'Y' || choice_beverage == 'y');
}

int main() {
    long long int totalPrice = 0, food_quant = 0, beverage_quant = 0, total_items;
    char choice_item = 'Y';

    // Main menu loop
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
                system("cls");
                foodMenu(&totalPrice, &food_quant);
                break;

            case 2:
                system("cls");
                drinkMenu(&totalPrice, &beverage_quant);
                break;

            default:
                printf("Invalid category chosen. Please choose again.\n");
        }
        printf("Do you want to add another item?[Y/N]: ");
        scanf(" %c", &choice_item);
        getchar();
    } while (choice_item == 'Y' || choice_item == 'y');

    // Final receipt
    total_items = food_quant + beverage_quant;
    system("cls");
    printf("-----------------------------------------------------------------------------\n");
    printf("Item(s) bought: %lld\n", total_items);
    printf("Subtotal: %lld\n", totalPrice);
    printf("Thank you for shopping at Binus Minimarket!\n");

    return 0;
}
