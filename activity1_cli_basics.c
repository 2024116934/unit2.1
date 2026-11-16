// ELEC2645 Unit 2.1 Activity 1 - Command-Line Interface Basics
//
// This first version moves between the menu and its options by calling
// functions. Activity 2 will reorganise the same application using a
// finite state machine and one persistent main loop.

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159f

// Function prototypes
void main_menu(void);
int get_user_input(void);
void select_menu_item(int input);
void print_main_menu(void);
void go_back_to_main(void);

void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);
void menu_item_5(void);

int main(void)
{
    main_menu();
    return 0;
}

void main_menu(void)
{
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

int get_user_input(void)
{
    int input;

    printf("\nSelect item: ");
    scanf("%d", &input); // Assume valid integer input in Activity 1.

    return input;
}

void select_menu_item(int input)
{
    switch (input)
    {
        case 1:
            menu_item_1();
            break;

        case 2:
            menu_item_2();
            break;

        case 3:
            menu_item_3();
            break;

        case 4:
            menu_item_4();
            break;

        // Step 2: Add case 5 and call menu_item_5().

        case 6:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid selection. Exiting...\n");
            exit(1);
    }
}

void print_main_menu(void)
{
    printf("\n+-----------------------------------+\n");
    printf("|             Main menu             |\n");
    printf("+-----------------------------------+\n");
    printf("|  1. Square a number               |\n");
    printf("|  2. ASCII code to character       |\n");
    printf("|  3. Celsius to Fahrenheit         |\n");
    printf("|  4. Even or odd                   |\n");
    // Step 1: Print option 5, Area of a circle.
    printf("|  6. Exit                          |\n");
    printf("+-----------------------------------+\n");
}

// This returns to the menu by calling main_menu() again.
//
// The program works, but every trip through the menu adds another
// sequence of function calls. As the application grows, it becomes
// harder to see which part of the program controls the current mode.
//
// Activity 2 reorganises the same application using a finite state
// machine and one persistent main loop.
void go_back_to_main(void)
{
    char input;

    do
    {
        printf("\nEnter 'b' or 'B' to go back to the main menu: ");
        scanf(" %c", &input);
    }
    while (input != 'b' && input != 'B');

    main_menu();
}

void menu_item_1(void)
{
    int number;

    printf("\n>> Square a number\n");
    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Result: %d\n", number * number);
    go_back_to_main();
}

void menu_item_2(void)
{
    int code;

    printf("\n>> ASCII code to character\n");
    printf("Enter an ASCII code from 0 to 127: ");
    scanf("%d", &code);

    if (code < 0 || code > 127)
    {
        printf("Code is outside the ASCII range.\n");
    }
    else
    {
        printf("Character: %c\n", (char)code);
    }

    go_back_to_main();
}

void menu_item_3(void)
{
    float celsius;

    printf("\n>> Celsius to Fahrenheit\n");
    printf("Enter a temperature in C: ");
    scanf("%f", &celsius);

    float fahrenheit = celsius * 9.0f / 5.0f + 32.0f;
    printf("Result: %.2f F\n", fahrenheit);

    go_back_to_main();
}

void menu_item_4(void)
{
    int number;

    printf("\n>> Even or odd\n");
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("%d is even.\n", number);
    }
    else
    {
        printf("%d is odd.\n", number);
    }

    go_back_to_main();
}

void menu_item_5(void)
{
    float radius;
    float area;

    printf("\n>> Area of a circle\n");

    // Step 3: Ask the user to enter the radius.
    // Step 4: Calculate the area using PI * radius * radius.
    // Step 5: Print the radius and area to two decimal places using:
    // Area of circle with radius 10.00 = 314.16

    // These temporary assignments allow the incomplete starter code
    // to compile. Replace them when completing the steps above.
    radius = 0.0f;
    area = 0.0f;

    go_back_to_main();
}
