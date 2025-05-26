#include <iostream>
#include <string>
using namespace std;

struct ExpenseNode {
    string expenseName;
    float amount;
    ExpenseNode* next;

    ExpenseNode(string name, float amt) {
        expenseName = name;
        amount = amt;
        next = NULL;
    }
};

// Add new expense
void addExpense(ExpenseNode*& head, string name, float amount) {
    ExpenseNode* newExpense = new ExpenseNode(name, amount);
    newExpense->next = head;
    head = newExpense;
    cout << "Expense added: " << name << " - $" << amount << endl;
}

// View all expenses
void viewExpenses(ExpenseNode* head) {
    if (head == NULL) {
        cout << "No expenses recorded.\n";
        return;
    }

    float total = 0;
    cout << "\n--- Expenses ---\n";
    while (head != NULL) {
        cout << "- " << head->expenseName << ": $" << head->amount << endl;
        total += head->amount;
        head = head->next;
    }
    cout << "Total Expenses: $" << total << endl;
}

// Edit existing expense by name
void editExpense(ExpenseNode* head, string name) {
    while (head != NULL) {
        if (head->expenseName == name) {
            cout << "Found '" << name << "'.\n";
            cout << "Enter new name (or press enter to keep '" << name << "'): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                head->expenseName = newName;
            }

            cout << "Enter new amount (or -1 to keep $" << head->amount << "): ";
            float newAmount;
            cin >> newAmount;
            cin.ignore();
            if (newAmount >= 0) {
                head->amount = newAmount;
            }

            cout << "Expense updated.\n";
            return;
        }
        head = head->next;
    }
    cout << "Expense '" << name << "' not found.\n";
}

int main() {
    ExpenseNode* expenseHead = NULL;
    int choice;
    string name;
    float amount;

    do {
        cout << "\n--- Simple Expense Tracker ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Edit Expense\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1:
                cout << "Enter expense name: ";
                getline(cin, name);
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore();
                addExpense(expenseHead, name, amount);
                break;

            case 2:
                viewExpenses(expenseHead);
                break;

            case 3:
                cout << "Enter the name of the expense to edit: ";
                getline(cin, name);
                editExpense(expenseHead, name);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

