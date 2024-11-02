#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a bank account
struct Account
{
    char name[50];
    int accountNumber;
    float balance;
};

// Function declarations
void createAccount(struct Account accounts[], int *count);
void deposit(struct Account accounts[], int count);
void withdraw(struct Account accounts[], int count);
void checkBalance(struct Account accounts[], int count);

int main()
{
    struct Account accounts[100]; // Array to store up to 100 accounts
    int count = 0;                // Keeps track of the number of accounts

    int choice;
    while (1)
    {
        printf("\n--- Simple Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount(accounts, &count);
            break;
        case 2:
            deposit(accounts, count);
            break;
        case 3:
            withdraw(accounts, count);
            break;
        case 4:
            checkBalance(accounts, count);
            break;
        case 5:
            printf("Thank you for using the banking system!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void createAccount(struct Account accounts[], int *count)
{
    struct Account newAccount;
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter initial deposit: ");
    scanf("%f", &newAccount.balance);

    accounts[*count] = newAccount;
    (*count)++;
    printf("Account created successfully!\n");
}

void deposit(struct Account accounts[], int count)
{
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(struct Account accounts[], int count)
{
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            if (accounts[i].balance >= amount)
            {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance(struct Account accounts[], int count)
{
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < count; i++)
    {
        if (accounts[i].accountNumber == accountNumber)
        {
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}
