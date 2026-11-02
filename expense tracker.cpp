
#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to store expense details
struct Expense {
    char description[50];
    char category[30];
    float amount;
};

// Global variables
struct Expense expenses[MAX];
int count = 0;

// Function declarations
void addExpense();
void viewExpenses();
void calculateTotal();
void highestExpense();

int main() {
    int choice;

    do {
        printf("\n========== EXPENSE TRACKER ==========\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Find Highest Expense\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                calculateTotal();
                break;

            case 4:
                highestExpense();
                break;

            case 5:
                printf("\nThank you for using Expense Tracker!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to add a new expense
void addExpense() {

    if (count >= MAX) {
        printf("\nExpense limit reached!\n");
        return;
    }

    printf("\nEnter expense description: ");
    scanf(" %49[^\n]", expenses[count].description);

    printf("\nSelect Category:\n");
    printf("1. Food\n");
    printf("2. Travel\n");
    printf("3. Shopping\n");
    printf("4. Education\n");
    printf("5. Other\n");

    int cat;

    printf("Enter category number: ");
    scanf("%d", &cat);

    switch (cat) {

        case 1:
            strcpy(expenses[count].category, "Food");
            break;

        case 2:
            strcpy(expenses[count].category, "Travel");
            break;

        case 3:
            strcpy(expenses[count].category, "Shopping");
            break;

        case 4:
            strcpy(expenses[count].category, "Education");
            break;

        case 5:
            strcpy(expenses[count].category, "Other");
            break;

        default:
            strcpy(expenses[count].category, "Other");
            break;
    }

    printf("Enter amount: Rs. ");
    scanf("%f", &expenses[count].amount);

    if (expenses[count].amount <= 0) {
        printf("\nInvalid amount! Expense not added.\n");
        return;
    }

    count++;

    printf("\nExpense added successfully!\n");
}

// Function to display all expenses
void viewExpenses() {

    if (count == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    printf("\n========== ALL EXPENSES ==========\n");

    for (int i = 0; i < count; i++) {

        printf("\nExpense %d\n", i + 1);

        printf("Description: %s\n",
               expenses[i].description);

        printf("Category: %s\n",
               expenses[i].category);

        printf("Amount: Rs. %.2f\n",
               expenses[i].amount);
    }
}

// Function to calculate total expenses
void calculateTotal() {

    float total = 0;

    for (int i = 0; i < count; i++) {
        total = total + expenses[i].amount;
    }

    printf("\nTotal Expenses = Rs. %.2f\n", total);
}

// Function to find the highest expense
void highestExpense() {

    if (count == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    int maxIndex = 0;

    for (int i = 1; i < count; i++) {

        if (expenses[i].amount >
            expenses[maxIndex].amount) {

            maxIndex = i;
        }
    }

    printf("\n========== HIGHEST EXPENSE ==========\n");

    printf("Description: %s\n",
           expenses[maxIndex].description);

    printf("Category: %s\n",
           expenses[maxIndex].category);

    printf("Amount: Rs. %.2f\n",
           expenses[maxIndex].amount);
}

