#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

// The Expense Structure
struct Expense {
    std::string description;
    double amount;
};

// Global Vector for Storing Expenses
std::vector<Expense> expenses;

// Function Declarations
void addExpense();
void viewExpenses();
void calculateTotal();

// The main() Function
int main() {
    char choice;
    do {
        std::cout << "\n===== Expense Tracker Menu =====\n";
        std::cout << "1. Add a new expense\n";
        std::cout << "2. View all expenses\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addExpense();
                break;
            case '2':
                viewExpenses();
                break;
            case '3':
                std::cout << "👋 Exiting Expense Tracker. Goodbye!\n";
                break;
            default:
                std::cout << "❌ Invalid choice. Please select a valid option.\n";
        }
    } while (choice != '3');

    return 0;
}

// The addExpense() Function
void addExpense() {
    Expense newExpense;
    std::cout << "\nAdding a new expense...\n";
    std::cout << "Enter expense description: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::getline(std::cin, newExpense.description);
    std::cout << "Enter expense amount: ";
    std::cin >> newExpense.amount;

    if(std::cin.fail()) {
        std::cout << "❌ Invalid amount. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    expenses.push_back(newExpense);
    std::cout << "✅ Expense added successfully!\n";
}

// The viewExpenses() Function
void viewExpenses() {
    std::cout << "\n--- All Expenses ---\n";
    if (expenses.empty()) {
        std::cout << "No expenses recorded yet.\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < expenses.size(); ++i) {
        std::cout << i + 1 << ". Description: " << expenses[i].description
                  << ", Amount: $" << expenses[i].amount << "\n";
    }
    std::cout << "--------------------\n";
    calculateTotal();
}

// The calculateTotal() Function
void calculateTotal() {
    double total = 0.0;
    for (const auto& expense : expenses) {
        total += expense.amount;
    }
    std::cout << "Total Expense: $" << std::fixed << std::setprecision(2) << total << "\n";
}
