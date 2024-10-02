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

int order = 0;
int choice = 0;
int milk,chocolate,water;
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

