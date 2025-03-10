#include <iostream>
#include <limits>
using namespace std;

int currentbalance = 10000;
int savingsbalance = 10000;

bool pin();
void clearscreen();
void language();
void display();
void checkbalance();
void withdraw();
void deposit();

void clearscreen() {
    system("cls");  // Use "clear" for Linux/macOS
}

int main() {
    if (pin()) {
        language();
    }
    cout << "Thank you, visit again.\n";
    return 0;
}

bool pin() {
    int attempt = 3;
    while (attempt > 0) {
        int n;
        cout << "Enter the PIN: ";
        cin >> n;
        if (n == 1234) {
            cout << "Verified\n";
            return true;
        } else {
            cout << "Wrong password. Attempts left: " << --attempt << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        clearscreen();
    }

    cout << "Too many attempts! Your card is blocked.\n";
    return false;
}

void language() {
    int x;
    cout << "Select your language:\n";
    cout << "1) English\n";
    cout << "2) Hindi\n";
    cin >> x;
    if (x == 1) {
        display();  // **Fix: Ensures user stays in menu after selecting a language**
    } else {
        cout << "Incorrect option chosen.\n";
    }
}

void display() {
    while (true) {
        cout << "\n1) Cash Withdraw\n";
        cout << "2) Cash Deposit\n";
        cout << "3) Check Balance\n";
        cout << "4) Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        clearscreen();
        switch (choice) {
            case 1: withdraw(); break;
            case 2: deposit(); break;
            case 3: checkbalance(); break;
            case 4: return;
            default: cout << "Invalid choice, try again.\n";
        }
    }
}

void withdraw() {
    cout << "Select account:\n";
    cout << "1) Savings Account\n";
    cout << "2) Current Account\n";
    int choice, amount;
    cin >> choice;
    
    if (choice == 1 || choice == 2) {
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (choice == 1) {
            if (amount <= savingsbalance) {
                savingsbalance -= amount;
                cout << "Withdrawal successful. New Savings Balance: " << savingsbalance << endl;
            } else {
                cout << "Insufficient balance!\n";
            }
        } else {
            if (amount <= currentbalance) {
                currentbalance -= amount;
                cout << "Withdrawal successful. New Current Balance: " << currentbalance << endl;
            } else {
                cout << "Insufficient balance!\n";
            }
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void deposit() {
    cout << "Choose account type:\n";
    cout << "1) Current Account\n";
    cout << "2) Savings Account\n";
    int choice, amount;
    cin >> choice;

    if (choice == 1 || choice == 2) {
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (choice == 1) {
            currentbalance += amount;
            cout << "Deposit successful. New Current Balance: " << currentbalance << endl;
        } else {
            savingsbalance += amount;
            cout << "Deposit successful. New Savings Balance: " << savingsbalance << endl;
        }
    } else {
        cout << "Invalid choice.\n";
    }
}

void checkbalance() {
    cout << "Select account type:\n";
    cout << "1) Current Account\n";
    cout << "2) Savings Account\n";
    int choice;
    cin >> choice;

    if (choice == 1) cout << "Current Balance: " << currentbalance << endl;
    else if (choice == 2) cout << "Savings Balance: " << savingsbalance << endl;
    else cout << "Invalid choice.\n";
}
