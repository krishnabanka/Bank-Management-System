#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store account details
struct Account {
    int accountNumber;
    char name[50];
    char address[100];
    char phone[15];
    float balance;
};

// Array to store multiple accounts
struct Account accounts[100];
int totalAccounts = 0;

// Function declarations
void createAccount();
void depositMoney();
void withdrawMoney();
void checkBalance();
void displayAllAccounts();
void displayMenu();

// Main function
int main() {
    int choice;
    
    printf("\n\t\t\t\t========================================\n");
    printf(" \t\t\t\t  WELCOME TO BANK MANAGEMENT SYSTEM   \n");
    printf("\t\t\t\t========================================\n");
    
    do {
        displayMenu();
        printf("\n\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("\n\t\t\t\t========================================\n");
                printf(" \t\t\t\t Thank you for using our Bank System!  \n");
                printf("\t\t\t\t========================================\n");
                break;
            default:
                printf("\n\t\t\t\tInvalid choice! Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n\t\t\t\t========================================\n");
    printf(" \t\t\t\t          MAIN MENU                    \n");
    printf("\t\t\t\t========================================\n");
    printf(" \t\t\t\t [1] Create New Account\n");
    printf(" \t\t\t\t [2] Deposit Money\n");
    printf(" \t\t\t\t [3] Withdraw Money\n");
    printf(" \t\t\t\t [4] Check Balance\n");
    printf(" \t\t\t\t [5] Display All Accounts\n");
    printf(" \t\t\t\t [6] Exit\n");
    printf("\t\t\t\t========================================\n");
}

// Function to create a new account
void createAccount() {
    struct Account newAccount;
    
    printf("\n\t\t\t\t========================================\n");
    printf("  \t\t\t\t    CREATE NEW ACCOUNT                \n");
    printf("\t\t\t\t========================================\n");
    
    newAccount.accountNumber = totalAccounts + 1001; // Starting account number from 1001
    
    printf("\t\t\t\tAccount Number: %d\n", newAccount.accountNumber);
    
    printf("\t\t\t\tEnter Account Holder Name: ");
    getchar(); // Clear buffer
    gets(newAccount.name);
    
    printf("\t\t\t\tEnter Password: ");
    gets(newAccount.address);
    
    printf("\t\t\t\tEnter Phone Number: ");
    scanf("%s", newAccount.phone);
    
    printf("\t\t\t\tEnter Initial Deposit Amount: Rs. ");
    scanf("%f", &newAccount.balance);
    
    if(newAccount.balance < 500) {
        printf("\n\t\t\t\tMinimum deposit amount should be Rs. 500\n");
        printf("\t\t\t\tAccount creation failed!\n");
        return;
    }
    
    // Store account in array
    accounts[totalAccounts] = newAccount;
    totalAccounts++;
    
    printf("\n\t\t\t\t========================================\n");
    printf(" \t\t\t\t Account Created Successfully!         \n");
    printf(" \t\t\t\t Your Account Number: %d               \n", newAccount.accountNumber);
    printf("\t\t\t\t========================================\n");
}

// Function to deposit money
void depositMoney() {
    int accNum, i, found = 0;
    float amount;
    
    
    printf("\n\t\t\t\t========================================\n");
    printf("   \t\t\t\t      DEPOSIT MONEY                  \n");
    printf("\t\t\t\t========================================\n");
    
    printf("\t\t\t\tEnter Account Number: ");
    scanf("%d", &accNum);
    
    // Search for account
    for(i = 0; i < totalAccounts; i++) {
        if(accounts[i].accountNumber == accNum) {
            found = 1;
            
            printf("\t\t\t\tAccount Holder: %s\n", accounts[i].name);
            printf("\t\t\t\tCurrent Balance: Rs. %.2f\n", accounts[i].balance);
            
            printf("\n\t\t\t\tEnter amount to deposit: Rs. ");
            scanf("%f", &amount);
            
            if(amount <= 0) {
                printf("\n\t\t\t\tInvalid amount!\n");
                return;
            }
            
            accounts[i].balance += amount;
            
            printf("\n\t\t\t\t========================================\n");
            printf(" \t\t\t\t Deposit Successful!                   \n");
            printf(" \t\t\t\t New Balance: Rs. %.2f                 \n", accounts[i].balance);
            printf("\t\t\t\t========================================\n");
            
            break;
        }
    }
    
    if(!found) {
        printf("\n\t\t\t\tAccount not found!\n");
    }
}

// Function to withdraw money
void withdrawMoney() {
    int accNum, i, found = 0;
    float amount;
    
    printf("\n\t\t\t\t========================================\n");
    printf("  \t\t\t\t      WITHDRAW MONEY                  \n");
    printf("\t\t\t\t========================================\n");
    
    printf("\t\t\t\tEnter Account Number: ");
    scanf("%d", &accNum);
    
    // Search for account
    for(i = 0; i < totalAccounts; i++) {
        if(accounts[i].accountNumber == accNum) {
            found = 1;
            
            printf("\t\t\t\tAccount Holder: %s\n", accounts[i].name);
            printf("\t\t\t\tCurrent Balance: Rs. %.2f\n", accounts[i].balance);
            
            printf("\n\t\t\t\tEnter amount to withdraw: Rs. ");
            scanf("%f", &amount);
            
            if(amount <= 0) {
                printf("\n\t\t\t\tInvalid amount!\n");
                return;
            }
            
            // Check if minimum balance is maintained
            if(accounts[i].balance - amount < 500) {
                printf("\n\t\t\t\tInsufficient balance!\n");
                printf("\t\t\t\tMinimum balance of Rs. 500 must be maintained.\n");
                return;
            }
            
            accounts[i].balance -= amount;
            
            printf("\n\t\t\t\t========================================\n");
            printf(" \t\t\t\t Withdrawal Successful!                \n");
            printf(" \t\t\t\t New Balance: Rs. %.2f                 \n", accounts[i].balance);
            printf("\t\t\t\t========================================\n");
            
            break;
        }
    }
    
    if(!found) {
        printf("\n\t\t\t\tAccount not found!\n");
    }
}

// Function to check account balance
void checkBalance() {
    int accNum, i, found = 0;
    
    printf("\n\t\t\t\t========================================\n");
    printf("  \t\t\t\t      CHECK BALANCE                   \n");
    printf("\t\t\t\t========================================\n");
    
    printf("\t\t\t\tEnter Account Number: ");
    scanf("%d", &accNum);
    
    // Search for account
    for(i = 0; i < totalAccounts; i++) {
        if(accounts[i].accountNumber == accNum) {
            found = 1;
            
            printf("\n\t\t\t\t========================================\n");
            printf(" \t\t\t\t ACCOUNT DETAILS                       \n");
            printf("\t\t\t\t========================================\n");
            printf(" \t\t\t\t Account Number: %d\n", accounts[i].accountNumber);
            printf(" \t\t\t\t Account Holder: %s\n", accounts[i].name);
            printf(" \t\t\t\t Password: %s\n", accounts[i].address);
            printf(" \t\t\t\t Phone: %s\n", accounts[i].phone);
            printf(" \t\t\t\t Current Balance: Rs. %.2f\n", accounts[i].balance);
            printf("\t\t\t\t========================================\n");
            
            break;
        }
    }
    
    if(!found) {
        printf("\n\t\t\t\tAccount not found!\n");
    }
}

// Function to display all accounts
void displayAllAccounts() {
    int i;
    
    printf("\n\t\t\t\t========================================\n");
    printf("  \t\t\t\t      ALL ACCOUNT DETAILS             \n");
    printf("\t\t\t\t========================================\n");
    
    if(totalAccounts == 0) {
        printf("\n\t\t\t\tNo accounts found!\n");
        return;
    }
    
    printf("\n\t\t\t\t%-12s %-25s %-15s %-12s\n", "Acc. No.", "Name", "Phone", "Balance");
    printf("\t\t\t\t------------------------------------------------------------------------\n");
    
    for(i = 0; i < totalAccounts; i++) {
        printf("\t\t\t\t%-12d %-25s %-15s Rs. %.2f\n", 
               accounts[i].accountNumber,
               accounts[i].name,
               accounts[i].phone,
               accounts[i].balance);
    }
    
    printf("\t\t\t\t========================================\n");
    printf("\t\t\t\tTotal Accounts: %d\n", totalAccounts);
    printf("\t\t\t\t========================================\n");
}
