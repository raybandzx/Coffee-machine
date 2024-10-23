#include <stdio.h>
#include <string.h>

#define ESP_BEANS 8
#define CAPPUCCINO_BEANS 8
#define MOCHA_CHOCOLATE 30

float ESP_PRICE = 3.5;
float CAPPUCCINO_PRICE = 4.5;
float MOCHA_PRICE = 5.5;
#define ADMIN_PASSWORD "admin_password"

#define THRESHOLD_BEANS 50
#define THRESHOLD_WATER 50
#define THRESHOLD_MILK 50
#define THRESHOLD_CHOCOLATE 20

int available_beans = 400;
int available_water = 400;
int available_milk = 400;
int available_chocolate = 120;
float total_amount = 0;

void coffee_menu();
void admin_mode();

int main() {
    int choice;
    while (1) {
        printf("\nCoffee Maker Menu\n");
        printf("1. Order coffee\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            coffee_menu();
        } else if (choice == 2) {
            admin_mode();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
    return 0;
}

void coffee_menu() {
    int order = 0;
    int confirm = 0;
    float payment = 0.0;

    while (1) {
        printf("\nChoose your order:\n");
        printf("1. Espresso AED %.2f\n", ESP_PRICE);
        printf("2. Cappuccino AED %.2f\n", CAPPUCCINO_PRICE);
        printf("3. Mocha AED %.2f\n", MOCHA_PRICE);
        printf("4. Exit\n");
        scanf("%d", &order);

        if (order == 4) {
            break;
        }

        float price = 0.0;
        switch (order) {
            case 1:
                if (available_beans >= ESP_BEANS && available_milk >= 0 && available_water >= 50) {
                    price = ESP_PRICE;
                    printf("You have ordered an espresso. Your total is %.2f\n", ESP_PRICE);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");
                }
                break;
            case 2:
                if (available_beans >= CAPPUCCINO_BEANS && available_milk >= 50 && available_water >= 50) {
                    price = CAPPUCCINO_PRICE;
                    printf("You have ordered a Cappuccino. Your total is %.2f\n", CAPPUCCINO_PRICE);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");
                }
                break;
            case 3:
                if (available_beans >= ESP_BEANS && available_milk >= 50 && available_water >= 50 && available_chocolate >= MOCHA_CHOCOLATE) {
                    price = MOCHA_PRICE;
                    printf("You have ordered a Mocha. Your total is %.2f\n", MOCHA_PRICE);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");
                }
                break;
            default:
                printf("Invalid choice. Try again.\n");
                continue;
        }

        printf("Confirm your selection. Enter 0 for no and 1 for yes: ");
        scanf("%d", &confirm);
        if (confirm == 0) {
            continue;
        }

        payment = 0.0;
        while (payment < price) {
            printf("Insert coin: ");
            float coin;
            scanf("%f", &coin);
            if (coin == 1.0 || coin == 0.5) {
                payment += coin;
            } else {
                printf("Please enter a valid coin.\n");
            }
        }
        total_amount += price;

        switch (order) {
            case 1:
                available_beans -= ESP_BEANS;
                available_water -= 50;
                break;
            case 2:
                available_beans -= CAPPUCCINO_BEANS;
                available_water -= 50;
                available_milk -= 50;
                break;
            case 3:
                available_beans -= ESP_BEANS;
                available_water -= 50;
                available_milk -= 50;
                available_chocolate -= MOCHA_CHOCOLATE;
                break;
        }

        if (available_beans <= THRESHOLD_BEANS) {
            printf("Alert: Beans running low!\n");
        }
        if (available_water <= THRESHOLD_WATER) {
            printf("Alert: Water running low!\n");
        }
        if (available_milk <= THRESHOLD_MILK) {
            printf("Alert: Milk running low!\n");
        }
        if (available_chocolate <= THRESHOLD_CHOCOLATE) {
            printf("Alert: Chocolate running low!\n");
        }
    }
}

void admin_mode() {
    char password[50];

    while (1) {
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp(ADMIN_PASSWORD, password) == 0) {
            int option;
            while (1) {
                printf("1. Display the quantity of each ingredient and the total sale amount\n");
                printf("2. Replenish ingredients in the machine\n");
                printf("3. Change the coffee prices\n");
                printf("4. Exit Admin mode\n");
                scanf("%d", &option);

                if (option == 4) {
                    break;
                }

                switch (option) {
                    case 1:
                        printf("Available Beans: %d\n", available_beans);
                        printf("Available Water: %d\n", available_water);
                        printf("Available Milk: %d\n", available_milk);
                        printf("Available Chocolate: %d\n", available_chocolate);
                        printf("Total sales: %.2f\n", total_amount);
                        break;
                    case 2:
                        int replenish_amount;
                        printf("Enter amount to replenish for beans, water, milk, and chocolate:\n");
                        printf("Beans: ");
                        scanf("%d", &replenish_amount);
                        available_beans += replenish_amount;
                        printf("Water: ");
                        scanf("%d", &replenish_amount);
                        available_water += replenish_amount;
                        printf("Milk: ");
                        scanf("%d", &replenish_amount);
                        available_milk += replenish_amount;
                        printf("Chocolate: ");
                        scanf("%d", &replenish_amount);
                        available_chocolate += replenish_amount;
                        printf("Ingredients replenished successfully!\n");
                        break;
                    case 3:
                        float new_price;
                        printf("Enter new price for Espresso: ");
                        scanf("%f", &new_price);
                        ESP_PRICE = new_price;
                        printf("Enter new price for Cappuccino: ");
                        scanf("%f", &new_price);
                        CAPPUCCINO_PRICE = new_price;
                        printf("Enter new price for Mocha: ");
                        scanf("%f", &new_price);
                        MOCHA_PRICE = new_price;
                        printf("Prices updated successfully!\n");
                        break;
                    default:
                        printf("Invalid option. Try again.\n");
                }
            }
        } else {
            printf("Invalid password\n");
            break;
        }
    }
}
