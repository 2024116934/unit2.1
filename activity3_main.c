// ELEC2645 Unit 2.1 Activity 3 - Modular CLI
//
// main.c contains the finite state machine and printed interface.
// calculator.c contains reusable calculations.
// input.c contains reusable validated input.

#include <stdio.h>
#include "activity3_calculator.h"
#include "activity3_input.h"

typedef enum
{
    STATE_MAIN_MENU,
    STATE_ADD,
    STATE_SUBTRACT,
    STATE_MULTIPLY,
    STATE_DIVIDE,
    STATE_EXIT
} AppState;

// Run the menu and return the next state based on user selection.
AppState run_menu(void);

// Read two integers from the user and store them in the provided pointers.
int read_two_integers(int *a, int *b);

int main(void)
{
    // Start in the main menu state.
    AppState state = STATE_MAIN_MENU;

    // The main loop continues until the user chooses to exit.
    while (state != STATE_EXIT)
    {
        // If in the main menu state, run the menu and update the state based on user selection.
        if (state == STATE_MAIN_MENU)
        {
            state = run_menu(); // next loop iteration will handle the new state
        }
        
        // If not in the main menu state, read two integers and perform the corresponding operation.
        else
        {
            int a;
            int b;

            // Read two integers from the user. If the input is invalid, return to the main menu.
            // Notice how we can check if the input is valid and handle errors just by checking if the 
            // function returned true or false. This is a good example of how modular code can make
            // the main program easier to read and understand. Well done us
            if (!read_two_integers(&a, &b))
            {
                printf("Invalid input. Returning to the menu.\n");
                state = STATE_MAIN_MENU;
                continue;
            }

            // Now we have our two integers, we can perform the operation corresponding to the current state.
            switch (state)
            {
                case STATE_ADD:
                    printf("Result: %d\n", calculator_add(a, b));
                    break;

                case STATE_SUBTRACT:
                    printf("Result: %d\n", calculator_subtract(a, b));
                    break;

                case STATE_MULTIPLY:
                    printf("Result: %d\n", calculator_multiply(a, b)); // This function is incomplete
                    break;

                case STATE_DIVIDE:
                {
                    int result;

                    // The calculator_divide() function is designed to handle division by zero gracefully. 
                    // It returns 0 if the denominator is zero, and 1 if the division was successful. 
                    // This allows us to check the return value and provide appropriate feedback to the user.

                    if (calculator_divide(a, b, &result)) // This function is incomplete
                    {
                        printf("Result: %d\n", result);
                    }
                    else
                    {
                        printf("Cannot divide by zero.\n");
                    }
                    break;
                }

                default:
                {
                    // This should never happen, but it's good practice to handle unexpected cases.
                    printf("Unexpected state. Returning to the menu.\n");
                }
                    break;
            }

            state = STATE_MAIN_MENU;
        }
    }

    printf("Exiting program...\n");
    return 0;
}

AppState run_menu(void)
{
    int selection;

    printf("\nModular calculator\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");

    if (!read_integer("Select item: ", &selection))
    {
        printf("Invalid input. Please enter a menu number.\n");
        return STATE_MAIN_MENU;
    }

    switch (selection)
    {
        case 1: return STATE_ADD;
        case 2: return STATE_SUBTRACT;
        case 3: return STATE_MULTIPLY;
        case 4: return STATE_DIVIDE;
        case 5: return STATE_EXIT;
        default:
            printf("Invalid menu selection.\n");
            return STATE_MAIN_MENU;
    }
}

int read_two_integers(int *a, int *b)
{
    // read_integer() returns true if the input was valid, false otherwise. 
    // We can use this with a logical AND (&&) to check if both inputs were valid.
    return read_integer("Enter the first integer: ", a)
        && read_integer("Enter the second integer: ", b);
}
