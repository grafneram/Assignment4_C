//Ashley Grafner
//9/17/2024
//Question 1

#include <stdio.h>
#include <tgmath.h> //used for pow

// initialize functions
int calculator();
void simpleInterest();
void areaCalculator();
int factorial(int n);

int main() {// Main method
    int choice;

    do {
        printf("\nChoose a task:\n");
        printf("1. Calculator (+, -, *, /, %%, !, ^)\n");
        printf("2. Simple Interest\n");
        printf("3. Area of Rectangle/Circle/Triangle\n");
        printf("Enter your choice (1-4): "); //asks the user for their input (1-4)
        scanf("%d", &choice);

        switch (choice) {
            case 1: //if 1 is entered
                calculator();
                break;
            case 2: // if 2 is entered
                simpleInterest();
                break;
            case 3: // if 3 is entered
                areaCalculator();
                break;
            case 4:
                printf("Exiting...\n");
                break; // Exits the loop
            default: //default case if 1, 2, or 3 isn't entered
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

// Calculator function
int calculator() {
    char operation;
    double num1, num2, result;
    int n;

    int factorial(int n) {
        // Function to calculate factorial, see if operation == ! bellow
        // Base cases: if n is 0 or 1, return 1 as the factorial of 0 and 1 is 1
        if (n == 0 || n == 1)
            return 1;
        else
            // Recursive case: n! = n * (n-1)!
                return n * factorial(n - 1);
    }

    printf("\nEnter operation (+, -, *, /, %%, !, ^): ");
    scanf(" %c", &operation);

    if (operation == '!') { // Factorial case
        printf("Enter an integer: ");
        scanf("%d", &n);
        result = factorial(n);
        printf("%d! = %lf\n", n, result);
    } else {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2); // Can handle doubles

        switch (operation) {
            case '+': // Add case
                result = num1 + num2;
                printf("Result: %lf\n", result);
                break;
            case '-': // Subtract case
                result = num1 - num2;
                printf("Result: %lf\n", result);
                break;
            case '*': // Multiply case
                result = num1 * num2;
                printf("Result: %lf\n", result);
                break;
            case '/': // Divide case
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %lf\n", result);
                } else {
                    printf("Error: Division by zero.\n");
                }
                break;
            case '%': // Modulo case
                if ((int)num2 != 0) {
                    result = (int)num1 % (int)num2;
                    printf("Result: %d\n", (int)result);
                } else {
                    printf("Error: Division by zero.\n");
                }
                break;
            case '^': // Power case
                result = pow(num1, num2);
                printf("Result: %lf\n", result);
                break;
            default:
                printf("Invalid operation.\n");
        }
    }

    return 0;
}


// Function to calculate simple interest
// Formula: Simple Interest = (Principal * Rate * Time) / 100
void simpleInterest() {
    double principal, rate, time, interest;

    // Prompt user for the principal amount
    printf("\nEnter principal amount: ");
    scanf("%lf", &principal);

    // Prompt user for the annual interest rate
    printf("Enter annual interest rate (in %%): ");
    scanf("%lf", &rate);

    // Prompt user for the time period in years
    printf("Enter time in years: ");
    scanf("%lf", &time);

    // Calculate simple interest using the formula
    interest = (principal * rate * time) / 100;

    // Display the calculated simple interest
    printf("Simple Interest = %lf\n", interest);
}

// Function to calculate the area of various shapes
void areaCalculator() {
    int shape; // Variable to store user's choice of shape
    double area, length, width, radius, base, height;
    const double PI = 3.14159; // Constant value for Pi to calculate the area of a circle

    // Display options for the user to choose a shape
    printf("\nChoose a shape to calculate area:\n");
    printf("1. Rectangle\n");
    printf("2. Circle\n");
    printf("3. Triangle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &shape);

    // Use a switch-case structure to handle different shape choices
    switch (shape) {
        case 1: // Case for rectangle
            // Prompt user for the length and width of the rectangle
            printf("Enter length and width of the rectangle: ");
            scanf("%lf %lf", &length, &width);
            // Calculate the area of the rectangle (Area = length * width)
            area = length * width;
            printf("Area of Rectangle = %lf\n", area); // Display the calculated area
            break;
        case 2: // Case for circle
            // Prompt user for the radius of the circle
            printf("Enter radius of the circle: ");
            scanf("%lf", &radius);
            // Calculate the area of the circle (Area = Pi * radius^2)
            area = PI * radius * radius;
            printf("Area of Circle = %lf\n", area); // Display the calculated area
            break;
        case 3: // Case for triangle
            // Prompt user for the base and height of the triangle
            printf("Enter base and height of the triangle: ");
            scanf("%lf %lf", &base, &height);
            // Calculate the area of the triangle (Area = 0.5 * base * height)
            area = 0.5 * base * height;
            printf("Area of Triangle = %lf\n", area); // Display the calculated area
            break;
        default: // Default case for invalid input
            printf("Invalid shape choice.\n"); // Display error message for invalid input
    }
}