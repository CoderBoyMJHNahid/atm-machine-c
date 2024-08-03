#include <stdio.h>
#include <stdlib.h>

void deposit(int *balance, int *atm_amount)
{
    system("cls");
    int amount;
    int option;
    printf("\n\tEnter the amount you want to deposit in your account: ");
    scanf("%d", &amount);

    if (amount >= 500 && amount % 500 == 0)
    {
        *balance = *balance + amount;
        *atm_amount = *atm_amount + amount;
        printf("\n\tDeposit successful. Your current balance is: %d\n", *balance);
    }
    else
        printf("\n\tInvalid deposit amount. Please deposit round of 500 taka notes\n");

    printf("\n\t Do you want to another deposit?\n");
    printf("\n\t 1. Yes\n");
    printf("\n\t 2. No\n");
    scanf("%d", &option);

    if (option == 1)
    {
        deposit(balance, atm_amount);
    }
    else
    {
        view_menu(balance, atm_amount);
    }
}
void withdraw(int *balance, int *atm_amount)
{
    system("cls");
    int amount;
    int option;
    printf("\n\tEnter the amount you want to withdraw in your account: ");
    scanf("%d", &amount);

    if (amount >= 500 && amount % 500 == 0)
    {

        if (amount > *balance)
        {
            printf("\n\tInsufficient balance. You can't withdraw more than your current balance.\n");
            fflush(stdin);
            getchar();
            view_menu(balance, atm_amount);
        }
        if (amount > *atm_amount)
        {
            printf("\n\tInsufficient balance. We don't have enough amount to do your request\n");
            fflush(stdin);
            getchar();
            view_menu(balance, atm_amount);
        }

        *balance = *balance - amount;
        *atm_amount = *atm_amount - amount;
        printf("\n\Withdraw successful. Your current balance is: %d\n", *balance);
    }
    else
        printf("\n\tInvalid withdraw amount. Please enter round number of 500 taka notes\n");

    printf("\n\t Do you want to another withdraw?\n");
    printf("\n\t 1. Yes\n");
    printf("\n\t 2. No\n");
    scanf("%d", &option);

    if (option == 1)
    {
        deposit(balance, atm_amount);
    }
    else
    {
        view_menu(balance, atm_amount);
    }
}
void view_menu(int *balance, int *atm_amount)
{

    int option;

    system("cls");
    printf("\tWelcome to ATM Service %c\n");
    printf("\t1. Check Balance\n");
    printf("\t2. Deposit Money\n");
    printf("\t3. Withdraw Money\n");
    printf("\t4. Exit\n");
    printf("\tEnter your choice: ");

    scanf("%d", &option);

    switch (option)
    {
    case 1:
        printf("\n\tYour current balance is: %d\n", *balance);
        break;
    case 2:
        deposit(balance, atm_amount);
        break;
    case 3:
        withdraw(balance, atm_amount);
        break;
    default:
        exit(1);
        break;
    }

    fflush(stdin);
    getchar();
    view_menu(balance, atm_amount);
}
int pwd_init(int pin)
{

    int pin_user;

    printf("\tEnter your pin: ");
    scanf("%d", &pin_user);

    if (pin_user == pin)
        return 1;
    else
        return 0;
}

void homepage(int pin, int *count, int *balance, int *atm_amount)
{
    system("cls");

    printf("\tWelcome to ATM Service\n");

    int exits = pwd_init(pin);

    if (exits)
    {
        view_menu(balance, atm_amount);
    }
    else
    {

        *count = *count - 1;

        if (*count == 0)
        {
            printf("\n\tYour account has been locked due to multiple unsuccessful login attempts.\n");
            printf("\tPlease contact your bank for further assistance.\n");
            exit(0);
        }

        printf("\n\tInvalid Pin! Please try again. You have %d attempt to login into your account\n", *count);
        fflush(stdin);
        getchar();

        homepage(pin, count, balance, atm_amount);
    }
}
int main()
{
    int pin_number = 1234;
    char name[256] = "M J H Nahid";
    int balance = 40000;

    int atm_amount = 100000;
    int count = 3;

    homepage(pin_number, &count, &balance, &atm_amount);

    return 0;
}