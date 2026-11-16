// ELEC2645 Unit 2.1 Activity 3 - Validated Input Library
//
// scanf() is convenient, but invalid text can remain in the input stream
// and interfere with later reads. This function reads a complete line using
// fgets(), then validates and converts the line using sscanf().
//


#include <stdio.h>
#include "activity3_input.h"

// Parameters:
// - prompt: The message to display to the user.
// - value: A pointer to an integer where the result will be stored if the input is valid.
// Returns:
// - 1 (true) if the input was valid and a single integer was successfully read.
// - 0 (false) if the input was invalid, contained extra characters, or an error occurred.
int read_integer(const char *prompt, int *value)
{
    char line[64];
    char extra;

    printf("%s", prompt);

    // fgets() reads a complete line (including the trailing '\n') into the character array.
    // Returns NULL if an error occurs or the input stream ends unexpectedly.
    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        return 0;
    }

    // sscanf() returns the total count of variables it successfully filled (0, 1, or 2).
    //
    // Mechanics of the format string "%d %c":
    // 1. "%d": Skips any leading whitespace and tries to read a valid integer into 'value'.
    // 2. " " (the space): Tells sscanf to consume and discard any trailing spaces or newlines '\n'.
    // 3. "%c": Looks for any leftover non-whitespace characters to trap in 'extra'.
    //
    // Expected Outcomes:
    // - Returns 1: It found a number, and %c found nothing else. (Valid input!)
    // - Returns 2: It found a number, but %c caught trailing text like "42abc" or "42 x". (Invalid!)
    // - Returns 0: It couldn't find a valid integer at the very start, like "abc". (Invalid!)
    if (sscanf(line, "%d %c", value, &extra) != 1)
    {
        return 0;
    }

    // We only reach this point if sscanf successfully matched exactly 1 item.
    return 1;
}
