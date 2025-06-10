#include <iostream>
using namespace std;

class TaxCalculator {
public:

    void calculateTax(int income) {
        double tax = income * 0.10;
        cout << "Flat 10% tax on income: " << tax << endl;
    }

    void calculateTax(int income, int age) {
        double tax;
        if (age < 60) {
            tax = income * 0.10;
        } else {
            tax = income * 0.05;
        }
        cout << "Tax based on age (" << age << "): " << tax << endl;
    }

    void calculateTax(double income) {
        double tax = income * 0.15;
        cout << "15% tax on double income: " << tax << endl;
    }
};

int main() {
    TaxCalculator tc;
    int choice;

    do {
        cout << "\n------ Tax Calculator Menu ------\n";
        cout << "1. Calculate tax with int income\n";
        cout << "2. Calculate tax with int income and age\n";
        cout << "3. Calculate tax with double income\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int income;
            cout << "Enter income (int): ";
            cin >> income;
            tc.calculateTax(income);
            break;
        }
        case 2: {
            int income, age;
            cout << "Enter income (int): ";
            cin >> income;
            cout << "Enter age (int): ";
            cin >> age;
            tc.calculateTax(income, age);
            break;
        }
        case 3: {
            double income;
            cout << "Enter income (double): ";
            cin >> income;
            tc.calculateTax(income);
            break;
        }
        case 4:
            cout << "Exiting Tax Calculator..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
