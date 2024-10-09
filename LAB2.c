#include <stdio.h>

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

#define esp_price 3.5
#define capp_price 4.5
#define mocha_price 5.5

#define coffee_menu

#define available_beans 400
#define available_water 400
#define available_milk 400
#define available_chocolate 120

int order = 0;
int choice = 0;
int confirm = 0;
int milk,chocolate,water;
int admin password = admin_password;
float price;

int main()
{
printf("Coffee Maker Menu\n");
printf("1. Order coffee\n");
printf("2. Admin mode\n");
printf("3. Exit\n");
printf("Enter your choice:");
scanf("%d", &choice);

while(choice !=1, choice !=2, choice !=3) {

    printf("Invalid input. Try again.\n");
    printf("Enter your choice from 1-3:");
    }

}


int coffee_menu()
while (choice == 1) {
    printf("Choose your order:");   
    printf("1. Espresso AED 3.5\n");
    printf("2. Cappucino AED 4.5\n");
    printf("3. Mocha AED 5.5\n");
    printf("4. Exit");
    scanf("%d", &order);

 switch (coffee_menu) {
  case 1:
    if(available_beans >= esp_beans && available_milk >= esp_milk && available_water >= esp_water)
    printf("You have ordered an espresso. Your total is %.2f",esp_price);
    else 
    printf("Unavailable due to temporarily insufficient ingredients");
    break;
  case 2:
    if(available_beans >= capp_beans && available_milk >= capp_milk && available_water >= capp_water)
    printf("You have ordered a Cappucino. Your total is %.2f",capp_price);
    else
    printf("Unavailable due to temporarily insufficient ingredients");
    break;
  case 3:
    if(available_beans >= mocha_beans && available_milk >= mocha_milk && available_water >= mocha_water && available_chocolate >= mocha_chocolate)
    printf("You have ordered a Mocha. Your total is %.2f",mocha_price);
    else 
    printf("Unavailable due to temporarily insufficient ingredients");
    break;    
 }
 printf("Confirm your selection. Enter 0 for no and 1 for yes");
 scanf("%d", &confirm);
 if(confirm == 1)
    continue;
}

int admin_mode()
while (choice == 2) {
    printf("Enter password:");
    scanf("%s", &password);
    if(strcmp(admin_password, password) == 0){
        int x;
        printf("1. Display the quantity of each ingredient in the machine and the total sale amount");
        scanf("%d", &x);
        printf("2. Replenish ingredients in the machine");
        replenish(x);  
        printf("3. Change the coffee price");
        change_price(x);
        printf("4. Exit the Admin mode");
    }
    else{
        printf("Invalid password")
        break;}
    
}
