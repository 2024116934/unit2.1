#ifndef ACTIVITY3_INPUT_H
#define ACTIVITY3_INPUT_H

// Reads an integer from the user with the given prompt. Returns true if the input was valid, false otherwise.
// Parameters:
// - prompt: The message to display to the user.
// - value: A pointer to an integer where the result will be stored if the input is valid.
// Returns:
// - 1 (true) if the input was valid and the integer was successfully read.
// - 0 (false) if the input was invalid or an error occurred.
int read_integer(const char *prompt, int *value);

#endif
