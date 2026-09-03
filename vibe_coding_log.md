Simple C Command-Line Program https://gemini.google.com/app/ab8fa2a6cf430417 

User prompt: I need to write a simple command-line program in C. I am a beginner, so please keep the code as simple as possible. Do not use external libraries, only standard ones like stdio and string. Here is the specification for the program: 1. It should run an infinite while loop that asks for user input using fgets. 2. If the user types 'exit', the loop should break and the program should end. 3. If the user types a sentence containing the word 'hello', the program should print a hardcoded greeting. 4. If the user types anything else, it should echo their input back to them. 5. Please add clear, line-by-line comments explaining what the code is doing. 

Response: This interactive C program fulfills your exact specifications using standard C libraries (<stdio.h> and <string.h>). 

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
        
        // Indicate to the OS that the program ran and exited successfully return 0; 
    } 

Key C Functions Explained 

fgets(input, sizeof(input), stdin): Reads user input safely up to a specific limit so memory cannot overflow. 
strcspn(input, "\n"): Finds the exact position of the newline key press (Enter) inside the string so we can strip it out before testing conditions. 
strcmp(input, "exit"): Returns 0 if two strings match identically. 
strstr(input, "hello"): Searches for the first occurrence of a substring ("hello") inside a larger string and returns non-NULL if found. 

How to Compile & Run 

Save the file as main.c. 
Compile in your terminal: gcc main.c -o program 
Run it: ./program 


User prompt: I have a compiled C program named harness. Write a very simple Bash script (for Linux/Mac) that automatically sends the word 'hello', followed by the word 'exit', into the program to test if it works. 

Response: You can pipe inputs directly into the standard input of ./harness using printf or a Here-Doc. 

    #!/bin/bash 
    #Send 'hello' followed by 'exit' into harness 
    printf "hello\nexit\n" | ./harness 

Alternative using a Here-Doc: 

If you plan to test many lines of input, a Here-Doc layout is cleaner to edit: 

    #!/bin/bash 
    ./harness << EOF 
    hello 
    exit 
    EOF 

How to run it: Save the code as test_harness.sh in the same directory as your compiled harness executable. 
Make the script executable: chmod +x test_harness.sh 
Execute the script: ./test_harness.sh
