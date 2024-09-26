//Ashley Grafner
//9/17/2024
//Question 4
/* Character arrays and display them as a string for;
All Capital letters from A-Z
All small letters from a-z
All numbers from 0-9 */

//NOTE: I also decided to include functions for this code, even though I didnt need to
#include <stdio.h>

// initialize all functions
void initializeCapitalLetters(char arr[]);
void initializeSmallLetters(char arr[]);
void initializeNumbers(char arr[]);
void displayArray(const char arr[], int size);

int main() { //main method
    // character arrays for each set of characters, type char
    char capital_letters[26]; //has 26 elements of char type
    char small_letters[26]; //has 26 elements of char type
    char numbers[10]; //has 10 elements of char type

    // Initialize the arrays
    initializeCapitalLetters(capital_letters);
    initializeSmallLetters(small_letters);
    initializeNumbers(numbers);

    // Display the arrays as strings
    printf("Capital letters: ");
    displayArray(capital_letters, 26);
    printf("\n");

    printf("Small letters: ");
    displayArray(small_letters, 26);
    printf("\n");

    printf("Numbers: ");
    displayArray(numbers, 10);
    printf("\n");

    return 0;
}

// Function to initialize capital letters array
void initializeCapitalLetters(char arr[]) {
    for (int i = 0; i < 26; i++) {
        arr[i] = 'A' + i; // ASCII values for capital letters
    }
}

// Function to initialize small letters array
void initializeSmallLetters(char arr[]) {
    for (int i = 0; i < 26; i++) {
        arr[i] = 'a' + i; // ASCII values for small letters
    }
}

// Function to initialize numbers array
void initializeNumbers(char arr[]) {
    for (int i = 0; i < 10; i++) {
        arr[i] = '0' + i; // ASCII values for numbers
    }
}

// Function to display a character array as a string
void displayArray(const char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
    }
}