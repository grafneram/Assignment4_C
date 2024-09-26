
//Ashley Grafner
//9/11/2024
/*Takes input of temp in Fahrenheit, then Iterate from 0 to user input by incrementing by 5 degrees
/Convert F to C and display in a table format

Changed on 9/17 so that it uses functions and/or arrays (didn't use arrays in this case)
*/
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to display the temperature table
void displayTemperatureTable(int maxFahrenheit, int step) {
    // Display the table header
    printf("_____________________________________________\n");
    printf("| degree Fahrenheit | degree Celsius      |\n");
    printf("_____________________________________________\n");

    // Iterating from 0 to maxFahrenheit by incrementing by step
    for (int i = 0; i <= maxFahrenheit; i += step) {
        // Convert Fahrenheit to Celsius using the function
        double celsius = fahrenheitToCelsius(i);

        // Print the Fahrenheit and Celsius values in a table row.
        printf("| %-18d | %-19.2f |\n", i, celsius);
        printf("______________________________________________\n"); // Formatting for bottom of table
    }
}

int main() {
    int maxFahrenheit; // Initialize maxFahrenheit
    int step = 5; // Increment step

    // Takes input from the user
    printf("Enter the maximum temperature in degrees Fahrenheit: ");
    scanf("%d", &maxFahrenheit); // Stores user input

    // Display the temperature table
    displayTemperatureTable(maxFahrenheit, step);

    return 0;
}
