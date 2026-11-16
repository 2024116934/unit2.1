// ELEC2645 Unit 2.1 Activity 2 - Command-Line Finite State Machine
//
// Activity 1 moved between the menu and its options by calling more
// functions. This version stores the current mode in one state variable.
// The central while loop runs the action for that state and then applies
// a transition to the next state.
//
// We are still assuming valid user inputs, we will look at better checking
// in a later activity

#include <stdio.h>

#define PI 3.14159f // math.h library has PI but we can use our own for now

// An enum gives a meaningful name to every possible application state.
typedef enum
{
    STATE_MAIN_MENU,
    STATE_SQUARE,
    STATE_ASCII,
    STATE_TEMPERATURE,
    STATE_EVEN_ODD,
    STATE_CIRCLE,
    STATE_EXIT
} AppState;

// Runs the main menu and returns the next state based on the user's selection.
AppState run_main_menu(void);

void print_main_menu(void);

// Simple calculations for each menu item. Each function runs the action for that state.
void run_square_state(void);
void run_ascii_state(void);
void run_temperature_state(void);
void run_even_odd_state(void);
void run_circle_state(void);

int main(void)
{
    // The application begins in the main-menu state.
    AppState state = STATE_MAIN_MENU;

    // This is the persistent main loop. The application remains inside
    // the loop until a transition changes state to STATE_EXIT.
    while (state != STATE_EXIT)
    {
        // The switch selects the action associated with the current state.
        // Most of these are quite simple at the moment, they run the action
        // and then return to the main menu. In a more complex application,
        // the action could return a different state to transition to.
        switch (state)
        {
            case STATE_MAIN_MENU:
                // The selected menu item determines the next state.
                state = run_main_menu();
                break;

            case STATE_SQUARE:
                run_square_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_ASCII:
                run_ascii_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_TEMPERATURE:
                run_temperature_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_EVEN_ODD:
                run_even_odd_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_CIRCLE:
                run_circle_state();
                state = STATE_MAIN_MENU;
                break;

            case STATE_EXIT:
                // The while condition normally prevents this case from
                // running, but listing it makes every enum state explicit.
                break;

            default:
                // Recover safely if state somehow contains another value.
                printf("Unknown state. Returning to the main menu.\n");
                state = STATE_MAIN_MENU;
                break;
        }
    }

    printf("Exiting program...\n");
    return 0;
}

AppState run_main_menu(void)
{
    int selection;

    print_main_menu();
    printf("\nSelect item: ");
    scanf("%d", &selection); // Assume valid integer input for now

    // The menu selection is an event. Returning a different enum value
    // causes the transition to the corresponding state.
    switch (selection)
    {
        case 1:
            return STATE_SQUARE;

        case 2:
            return STATE_ASCII;

        case 3:
            return STATE_TEMPERATURE;

        case 4:
            return STATE_EVEN_ODD;

        case 5:
            return STATE_CIRCLE;

        case 6:
            return STATE_EXIT;

        default:
            printf("Invalid menu selection.\n");
            return STATE_MAIN_MENU;
    }
}

void print_main_menu(void)
{
    printf("\n+-----------------------------------+\n");
    printf("|           FSM Main menu           |\n");
    printf("+-----------------------------------+\n");
    printf("|  1. Square a number               |\n");
    printf("|  2. ASCII code to character       |\n");
    printf("|  3. Celsius to Fahrenheit         |\n");
    printf("|  4. Even or odd                   |\n");
    printf("|  5. Area of a circle              |\n");
    printf("|  6. Exit                          |\n");
    printf("+-----------------------------------+\n");
}

void run_square_state(void)
{
    int number;

    printf("\n>> Square a number\n");
    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Result: %d\n", number * number);
}

void run_ascii_state(void)
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
}

void run_temperature_state(void)
{
    float celsius;

    printf("\n>> Celsius to Fahrenheit\n");
    printf("Enter a temperature in C: ");
    scanf("%f", &celsius);

    float fahrenheit = celsius * 9.0f / 5.0f + 32.0f;
    printf("Result: %.2f F\n", fahrenheit);
}

void run_even_odd_state(void)
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
}

void run_circle_state(void)
{
    float radius;
    float area;

    printf("\n>> Area of a circle\n");

    // Step 1: Ask the user to enter the radius.
    // Step 2: Reject a negative radius.
    // Step 3: Otherwise calculate the area using PI * radius * radius.
    // Step 4: Print the result using this format:
    // Area of circle with radius 10.00 = 314.16
    //
    // Do not call the menu from this function. main() performs the
    // transition back to STATE_MAIN_MENU after this action is complete.

    // Temporary assignments allow the incomplete starter to compile.
    radius = 0.0f;
    area = 0.0f;
}
