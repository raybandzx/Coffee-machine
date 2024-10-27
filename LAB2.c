#include <stdio.h> // Adding a standard header file
#include <string.h> // Adding a header file that is used to control strings

#define ESP_BEANS 8 // Defining the amount of beans needed to make an espresso
#define CAPPUCCINO_BEANS 8 // Defing the amount of beans needed to make a cappucino
#define MOCHA_CHOCOLATE 30 // Defining the amount of chocolate syrup required to make a mocha

float ESP_PRICE = 3.5; // Setting the price of an espresso
float CAPPUCCINO_PRICE = 4.5; // Setting the price of a cappucino
float MOCHA_PRICE = 5.5; // Setting the price of a mocha

//The threshold amount of something in the machine is the minimum amount it can reach before the system alerts the admin
#define THRESHOLD_BEANS 50 // Defining the threshold beans
#define THRESHOLD_WATER 50 // Defing the threshold water
#define THRESHOLD_MILK 50 // Defining the threshold milk
#define THRESHOLD_CHOCOLATE 20 // Defining the threshold chocolate syruo

//This is the total amount of ingredients that is set by the admin
int available_beans = 400; // The total amount of beans available in the machine
int available_water = 400; // The total amount of beans available in the machine
int available_milk = 400; // The total amount of beans available in the machine
int available_chocolate = 120; // The total amount of beans available in the machine
float total_amount = 0; // This is a variable used to store the total amount of money available in the machine that can only be accessed by the admin

void coffee_menu(); // The function that is used to order a coffee
void admin_mode(); // The function that is used for admin mode

// Main function
int main() { 
    int choice;
    while (1) {
        printf("\nCoffee Maker Menu\n"); // printf functions display the commands to the user
        printf("1. Order coffee\n");
        printf("2. Admin mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Checks the user input 
        
        if (choice == 1) { 
            coffee_menu(); // If the user chooses 1, then the machine will take them to the coffee menu
        } else if (choice == 2) {
            admin_mode();// If the user chooses 2, then the machine will take them to the admin mode
        } else if (choice == 3) {
            break; // If the user chooses 3, the user will exit the machine
        } else {
            printf("Invalid input. Try again.\n"); // For any other input, this will be displayed
        }
    }
    return 0; // End of main function
}

// Function for the customer to order a coffee
void coffee_menu() {
    int order = 0; // The variable is used to store the customer's order
    int confirm = 0; // The variable is used to store the user's confirmation on their order
    float payment = 0.0; // It is used to store the payment amount

    while (1) { // If the customer chose 1, the following will be displayed
        printf("\nChoose your order:\n"); // Asking the customer for their order
        printf("1. Espresso AED %.2f\n", ESP_PRICE); // Displaying espresso price
        printf("2. Cappuccino AED %.2f\n", CAPPUCCINO_PRICE); // Displaying cappucino price
        printf("3. Mocha AED %.2f\n", MOCHA_PRICE); // Dispalying mocha price
        printf("4. Exit\n"); // If the customer wants to exit from their order
        scanf("%d", &order); // Checks the customer order

        if (order == 4) {
            break; // End the loop if the customer chooses to exit
        }

        float price = 0.0; // Setting the initial price to 0
        switch (order) { // Determine the customer's ordef and check if the ingredients are available
            case 1: // When user orders an espresso
                if (available_beans >= ESP_BEANS && available_milk >= 0 && available_water >= 50) { // checking for espresso ingredients
                    price = ESP_PRICE; 
                    printf("You have ordered an espresso. Your total is %.2f\n", ESP_PRICE);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");// The statement that will be displayed if there is a shortage of ingredients
                }
                break;
            case 2: // When user orders a cappucino
                if (available_beans >= CAPPUCCINO_BEANS && available_milk >= 50 && available_water >= 50) { // checking for cappucino ingredients
                    price = CAPPUCCINO_PRICE; // Displaying the total
                    printf("You have ordered a Cappuccino. Your total is %.2f\n", CAPPUCCINO_PRICE); 
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n"); // The statement that will be displayed if there is a shortage of ingredients
                }
                break;
            case 3: // When user orders a mocha
                if (available_beans >= ESP_BEANS && available_milk >= 50 && available_water >= 50 && available_chocolate >= MOCHA_CHOCOLATE) { // checking for mocha ingredients
                    price = MOCHA_PRICE;
                    printf("You have ordered a Mocha. Your total is %.2f\n", MOCHA_PRICE);
                } else {
                    printf("Unavailable due to temporarily insufficient ingredients.\n");// The statement that will be displayed if there is a shortage of ingredients
                }
                break;
            default:
                printf("Invalid choice. Try again.\n"); // For an invalid input
                continue;
        }

        printf("Confirm your selection. Enter 0 for no and 1 for yes: "); // Asking the customer to confirm their selection
        scanf("%d", &confirm); // Checking for their confirmation
        if (confirm == 0) { 
            continue;
        }

        payment = 0.0; // The user's payment is set to 0
        while (payment < price) { // This is a loop that will continue until the user inserts the full amount
            printf("Insert coin: "); // Asking the user to insert a coin 
            float coin; // Variable used to store the amount of coins taht was inserted
            scanf("%f", &coin); // Checking the vale
            if (coin == 1.0 || coin == 0.5) { // The type of coins that are accepted by the machine
                payment += coin; // Adding the coins till it adds up to the total amount that should be paid
            } else {
                printf("Please enter a valid coin.\n"); // For any other coins
            }
        }
        total_amount += price; // Adding this money to the total sales


        switch (order) {
            case 1:
                available_beans -= ESP_BEANS; // Deduct these beans after an order from the available beans
                available_water -= 50; // Deduct the water 
                break;
            case 2:
                available_beans -= CAPPUCCINO_BEANS; // Deduct these beans after an order from the available beans
                available_water -= 50; // Deduct the water
                available_milk -= 50; // Deduct milk
                break;
            case 3:
                available_beans -= ESP_BEANS; // Deduct these beans after an order from the available beans
                available_water -= 50; // Deduct the water
                available_milk -= 50; // Deduct milk
                available_chocolate -= MOCHA_CHOCOLATE; // Deduct chocolate syrup
                break;
        }
/* Check the ingredients to alert if they are running low*/
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
int replenish_amount; // Amount to replenish ingredients
float new_price; // New price for the coffees
void admin_mode() {
    int ADMIN_PASSWORD; // Variable to store password input
    int password = 345678; // The password for admin mode
    while (1) {
        printf("Enter password: "); // Asking for the password
        scanf("%d", &ADMIN_PASSWORD); // Check the admin password
        if (ADMIN_PASSWORD == password) { 
            int option;
            while (1) {
                /* Display admin menu*/
                printf("1. Display the quantity of each ingredient and the total sale amount\n");
                printf("2. Replenish ingredients in the machine\n");
                printf("3. Change the coffee prices\n");
                printf("4. Exit Admin mode\n");
                scanf("%d", &option); // Check for the admin input

                if (option == 4) {
                    break;// end the loop
                }

                switch (option) {
                    case 1: // Displaying ingredient quantity and total sales
                        printf("Available Beans: %d\n", available_beans);
                        printf("Available Water: %d\n", available_water);
                        printf("Available Milk: %d\n", available_milk);
                        printf("Available Chocolate: %d\n", available_chocolate);
                        printf("Total sales: %.2f\n", total_amount);
                        break;
                    case 2: // Replenishing ingredients
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
                    case 3: // Changing coffee price
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
                    default: // For other inputs
                        printf("Invalid option. Try again.\n");
                }
            }
        } else {
            printf("Invalid password\n"); // If the incorrect password is entered
            break; // Exit the admin mode and retorn to the main menu
        }
    }
}
