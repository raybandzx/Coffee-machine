#include <stdio.h>
#include <string.h>

#define esp_beans 8
#define capp_beans 8
#define mocha_beans 8

#define esp_water 30
#define capp_water 30
#define mocha_water 39

#define esp_milk 0
#define capp_milk 70
#define mocha_milk 160

#define mocha_chocolate 30

#define admin_password "admin_password"
#define threshold_beans 50
#define threshold_water 50
#define threshold_milk 50
#define threshold_chocolate 20

float esp_price = 3.5;
float capp_price = 4.5;
float mocha_price = 5.5;

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
    float payment = 0;

    while (1) {
        printf("\nChoose your order:\n");
        printf("1. Espresso AED %.2f\n", esp_price);
        printf("2. Cappuccino AED %.2f\n", capp_price);
        printf("3. Mocha AED %.2f\n", mocha_price);
        printf("4. Exit\n");
        scanf("%d", &order);

        if (order == 4) {
            break;
        }
        float price = 0.0;
        switch (order) {
            case 1:
                if (available_beans >= esp_beans && available_milk >= esp_milk && available_water >= esp_water) {
                    price = esp_price;
                    printf("You have ordered an espresso. Your total is %.2f\n", esp_price);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");
                }
                break;
            case 2:
                if (available_beans >= capp_beans && available_milk >= capp_milk && available_water >= capp_water) {
                    price = capp_price;
                    printf("You have ordered a Cappuccino. Your total is %.2f\n", capp_price);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");
                }
                break;
            case 3:
                if (available_beans >= mocha_beans && available_milk >= mocha_milk && available_water >= mocha_water && available_chocolate >= mocha_chocolate) {
                    price = mocha_price;
                    printf("You have ordered a Mocha. Your total is %.2f\n", mocha_price);
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
                available_beans -= esp_beans;
                available_water -= esp_water;
                break;
            case 2:
                available_beans -= capp_beans;
                available_water -= capp_water;
                available_milk -= capp_milk;
                break;
            case 3:
                available_beans -= mocha_beans;
                available_water -= mocha_water;
                available_milk -= mocha_milk;
                available_chocolate -= mocha_chocolate;
                break;
        }

        if (available_beans <= threshold_beans) {
            printf("Alert: Beans running low!\n");
        }
        if (available_water <= threshold_water) {
            printf("Alert: Water running low!\n");
        }
        if (available_milk <= threshold_milk) {
            printf("Alert: Milk running low!\n");
        }
        if (available_chocolate <= threshold_chocolate) {
            printf("Alert: Chocolate running low!\n");
        }
    }
}

void admin_mode() {
    char password[50];  // Declare the password variable
    while (1) {
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp(admin_password, password) == 0) {
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
                        esp_price = new_price;

                        printf("Enter new price for Cappuccino: ");
                        scanf("%f", &new_price);
                        capp_price = new_price;

                        printf("Enter new price for Mocha: ");
                        scanf("%f", &new_price);
                        mocha_price = new_price;

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
