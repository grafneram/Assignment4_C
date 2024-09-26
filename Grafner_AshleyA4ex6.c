//Ashley Grafner
//9/17/2024
//Question 6
//Prints if the user input number is an Armstrong number.

#include <stdio.h>
#include <math.h> //used for pow

//initialize our functions
int count_digits(int number);
int is_armstrong(int number);

int main() {
    int number;
    printf("Enter a number (1 - 999999): "); // Prompt the user to enter a number
    scanf("%d", &number);

    // Check if the entered number is within the valid range
    if (number < 1 || number > 999999) {
        printf("Number out of range. Please enter a number between 1 and 999999.\n");
        return 1; // Exit the program with an error code
    }

    if (is_armstrong(number)) {  // Check if the number is an Armstrong number
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0; // Exit the program successfully
}


int count_digits(int number) { // Function to count the number of digits in a number
    int digits = 0;
    while (number != 0) {
        number /= 10;
        ++digits;
    }
    return digits;
}

int is_armstrong(int number) { // Function to check if a number is an Armstrong number
    int temp = number, remainder, digits, sum = 0;

    // Get the number of digits in the number
    digits = count_digits(number);

    // Calculate the sum of each digit raised to the power of the number of digits
    while (temp != 0) {
        remainder = temp % 10;    // Get the last digit
        sum += pow(remainder, digits); // Add the digit raised to the power of digits to sum
        temp /= 10;               // Remove the last digit
    }

    // Return 1 (true) if the sum equals the original number, 0 (false) otherwise
    return sum == number;
}
