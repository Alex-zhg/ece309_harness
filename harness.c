#include <stdio.h>   // Include standard input/output functions (printf, fgets)
#include <string.h>  // Include string manipulation functions (strcmp, strstr, strcspn)

int main() {
    // Buffer to store up to 255 user-typed characters + 1 null terminator
    char input[256];

    // Start an infinite loop (1 is always true)
    while (1) {
        // Display a prompt to the user
        printf("Enter text: ");

        // Safely read a line of text from standard input (keyboard)
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Stop loop if input reading fails or EOF occurs
        }

        // Remove trailing newline character '\n' added by fgets
        input[strcspn(input, "\n")] = '\0';

        // Requirement 2: Check if the user typed "exit"
        if (strcmp(input, "exit") == 0) {
            printf("Exiting program. Goodbye!\n"); // Farewell message
            break;                                 // Terminate the while loop
        }

        // Requirement 3: Check if the input contains the word "hello" anywhere
        if (strstr(input, "hello") != NULL) {
            printf("Hello there! Hope you are having a wonderful day!\n");
        } 
        // Requirement 4: If neither condition matched, echo the input back
        else {
            printf("Echo: %s\n", input);
        }
    }

    // Indicate to the OS that the program ran and exited successfully
    return 0;
}