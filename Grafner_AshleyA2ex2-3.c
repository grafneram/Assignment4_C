#include <stdio.h>
#include <stdbool.h>

//Ashley Grafner
//9/11/2024
//Question 6 for Assignment 3. changed for Question 2 for Assignment 4
// Changed to use functions instead

// Function declarations
void getEmployeeDetails(char name[], int *rec_num, char *dept, int *salary, char *gender, char *nationality);
bool validateDepartment(char dept);
bool validateSalary(char dept, int salary);
bool validateGender(char gender);
void mapNationality(char nationality, char nationalityName[]);
void printEmployeeDetails(int rec_num, char name[], char gender, char dept, int salary, int leave, char nationalityName[], bool ML);

int main() {
    int rec_num, salary;
    char name[100];       // Employee name
    char gender;          // Employee gender (F for Female, M for Male, O for Other)
    char dept;            // Employee department (A, B, or C)
    char nationality;    // Employee nationality code
    char nationalityName[30]; // To store nationality name
    bool ML = false;     // Flag to indicate if maternity leave is allowed

    // Assign a constant value for leave days
    int leave = 15; // constant assignment

    // Get employee details
    getEmployeeDetails(name, &rec_num, &dept, &salary, &gender, &nationality);

    // Determine if maternity leave is allowed
    if (gender == 'F') {
        ML = true;
    }

    // Map nationality code to country name
    mapNationality(nationality, nationalityName);

    // Print formatted employee details
    printEmployeeDetails(rec_num, name, gender, dept, salary, leave, nationalityName, ML);

    return 0;
}

// Function definitions
void getEmployeeDetails(char name[], int *rec_num, char *dept, int *salary, char *gender, char *nationality) {
    // Prompt the user to enter the employee name
    printf("Enter employee name: ");
    scanf("%s", name);
    getchar(); // Consume the newline character left by scanf

    // Prompt the user to enter the employee number
    printf("Enter employee number: ");
    scanf("%d", rec_num);
    getchar(); // Consume the newline character left by scanf

    // Get department input and validate it
    while (true) {
        printf("Enter Department A, B, or C: ");
        scanf("%c", dept);
        getchar(); // Consume the newline character left by scanf

        if (validateDepartment(*dept)) {
            break; // Exit loop if input is valid
        }
        // Inform the user of invalid input and prompt again
        printf("Invalid input\n");
    }

    // Get salary input based on department and validate it
    while (true) {
        switch (*dept) {
            case 'A':
                printf("Enter employee salary between 1000 to 5000: ");
                break;
            case 'B':
                printf("Enter employee salary between 5001 to 10000: ");
                break;
            case 'C':
                printf("Enter employee salary between 10001 to 20000: ");
                break;
            default:
                printf("Invalid department\n");
                continue;
        }
        scanf("%d", salary);
        getchar(); // Consume the newline character left by scanf

        if (validateSalary(*dept, *salary)) {
            break; // Exit loop if salary is within valid range
        }
        // Inform the user of invalid salary and prompt again
        printf("Invalid salary\n");
    }

    // Get gender input and validate it
    while (true) {
        printf("Enter %s gender F, M, or O: ", name);
        scanf("%c", gender);
        getchar(); // Consume the newline character left by scanf

        if (validateGender(*gender)) {
            break; // Exit loop if input is valid
        }
        // Inform the user of invalid input and prompt again
        printf("Invalid input\n");
    }

    // Get nationality input and map to country name
    while (true) {
        printf("Enter nationality (0-9):\n0. USA\n1. Canada\n2. Mexico\n3. UK\n4. Germany\n5. France\n6. Japan\n7. China\n8. India\n9. Australia\n");
        scanf("%c", nationality); // Read the nationality input from the user
        getchar(); // Consume the newline character left by scanf

        // Check if the input is a valid nationality code
        if (*nationality >= '0' && *nationality <= '9') {
            break; // If valid, exit the loop
        }
        printf("Invalid input\n"); // If the input is invalid, print an error message
    }
}

bool validateDepartment(char dept) {
    return (dept == 'A' || dept == 'B' || dept == 'C');
}

bool validateSalary(char dept, int salary) {
    if (dept == 'A') return (salary >= 1000 && salary <= 5000);
    if (dept == 'B') return (salary >= 5001 && salary <= 10000);
    if (dept == 'C') return (salary >= 10001 && salary <= 20000);
    return false;
}

bool validateGender(char gender) {
    return (gender == 'F' || gender == 'M' || gender == 'O');
}

void mapNationality(char nationality, char nationalityName[]) {
    switch (nationality) {
        case '0': sprintf(nationalityName, "USA"); break;
        case '1': sprintf(nationalityName, "Canada"); break;
        case '2': sprintf(nationalityName, "Mexico"); break;
        case '3': sprintf(nationalityName, "UK"); break;
        case '4': sprintf(nationalityName, "Germany"); break;
        case '5': sprintf(nationalityName, "France"); break;
        case '6': sprintf(nationalityName, "Japan"); break;
        case '7': sprintf(nationalityName, "China"); break;
        case '8': sprintf(nationalityName, "India"); break;
        case '9': sprintf(nationalityName, "Australia"); break;
        default: sprintf(nationalityName, "N/A"); break;
    }
}

void printEmployeeDetails(int rec_num, char name[], char gender, char dept, int salary, int leave, char nationalityName[], bool ML) {
    // Print formatted employee details
    printf("Formatted Employee Details: \n%d\t%s\t%c\t%c\t%d\t%d\t%s\n", rec_num, name, gender, dept, salary, leave, nationalityName);
    printf("Employee Summary: \nEmployee number: %d\nEmployee name: %s\nEmployee gender: %c\nEmployee department: %c\nEmployee Salary: %d\nEmployee leaves accumulation: %d\nEmployee nationality: %s\n", rec_num, name, gender, dept, salary, leave, nationalityName);

    // Print maternity leave information if applicable
    if (ML) {
        printf("Maternity leave allowed.\n");
    }
}
