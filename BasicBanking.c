// Bank Management System

#include <stdio.h>  //printf(),scanf()
#include <stdlib.h> //exit(0),system()
#include <conio.h>  //getch()
#include <time.h>   //time(),ctime()
#include <unistd.h> //usleep()
char name[20];
int d_amt, with_amt, trans_amt, amt = 55000, acc_no, acc_t, count = 0;

void deposit();
void withdraw();
void transfer();
void account_details();
void summary();
void transaction_details();
void menu();

void star()
{
    for (int i = 0; i < 50; i++)
    {
        printf("*");
    }
}


int main()
{
    FILE *ptr = fopen("Account.txt", "w");

    int ch;
    printf("Enter your name : ");
    gets(name);
    fprintf(ptr, "\nName : %s\n", name);
    call2:
    printf("Enter your account no. : ");
    scanf("%d", &acc_no);
    fprintf(ptr, "Account no. : %d\n", acc_no);

    fclose(ptr);
   
    {   call:
        menu();
        printf("\nChoose from the following:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            deposit();
            break;
        case 2:
            system("cls");
            withdraw();
            break;

        case 3:
            system("cls");
            transfer();
            break;

        case 4:
            system("cls");
            account_details();
            break;

        case 5:
            transaction_details();
            break;

        case 6:
            system("cls");
            summary();
            exit(0);

        default:
            printf("*****Invalid choice*****");
            sleep(2);
            goto call;
        }
    }
    goto call;
    return 0;
}

void menu()
{

    system("cls");
    star();
    printf("\n\t              MENU\n");

    star();
    printf("\n1.Deposit Money\n");
    printf("2.Withdraw Money\n");
    printf("3.Transfer Money\n");
    printf("4.Account details\n");
    printf("5.Transaction details\n");
    printf("6.Exit\n");
    star();
}

//!---------------------------------------------------------
void deposit()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    star();
    printf("\n        *****DEPOSITING MONEY*****\n");
    star();

    printf("\nEnter the amount to deposit: ");
    scanf("%d", &d_amt);
    amt += d_amt;
    printf("****Money Deposited****\n");
    printf("New balance : %d\n", amt);
    fprintf(ptr, "\nRs%d had been deposited to your account \n", d_amt);
    fprintf(ptr, "Date/Time of transaction:  %s\n", ctime(&tm));
    count++;

    fclose(ptr);
    printf("Going back to Menu......");
    sleep(3);
}

//!---------------------------------------------------------

void withdraw()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    star();
    printf("\n        *****WITHDRAWING MONEY*****\n");
    star();

    printf("\nEnter the amount to withdraw: ");
    scanf("%d", &with_amt);

    if (amt < with_amt)
    {
        printf("****Insufficient balance****\n");
    }
    else
    {
        amt = amt - with_amt;
        printf("*****Money withdrawn*****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been withdrawn from your account \n", with_amt);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Going back to Menu......");
    sleep(3);
}


void transfer()
{

    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account.txt", "a");
    star();
    printf("\n        *****TRANSFERRING MONEY*****\n");
    star();

    printf("\nEnter the account no. in which you want to transfer the money: ");
    scanf("%d", &acc_t);
    printf("Enter the amount you want to transfer: ");
    scanf("%d", &trans_amt);

    if (amt < trans_amt)
    {
        printf("****You have not sufficient balance****\n");
    }
    else
    {
        amt = amt - trans_amt;
        printf("****Money Transferred****\n");
        printf("Current balance : %d\n", amt);
        fprintf(ptr, "\nRs%d had been transferred from your account to %d\n", trans_amt, acc_t);
        fprintf(ptr, "Date/Time of transaction :  %s\n", ctime(&tm));
        count++;
    }
    fclose(ptr);
    printf("Going back to Menu......");
    sleep(3);
}

//!---------------------------------------------------------

void account_details()
{
    star();
    printf("\n        *****ACCOUNT DETAILS*****\n");
    star();

    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);
    printf("\n%d transactions have been made from your account \n", count);
    printf("Press any key to go back to Menu.\n");
    getch();
    printf("\nHeading back......");
    sleep(2);
}

//!---------------------------------------------------------

void transaction_details()
{

    system("cls");

    FILE *ptr;
    ptr = fopen("Account.txt", "r");
    char c = fgetc(ptr);
    if (c == EOF)
    {
        star();
        printf("\n        *****TRANSACTION DETAILS*****\n");
        star();
        printf("\n*******NO RECENT TRANSACTION*******\n");
    }
    else
    {
        star();
        printf("\n        *****TRANSACTION DETAILS*****\n");
        star();
        printf("\n%d transactions have been made from your account \n", count);
        while (c != EOF) // EOF=End of file
        {
            printf("%c", c);
            c = fgetc(ptr);
        }
    }
    printf("Press any key to go back to Menu.\n");
    getch();
    printf("\nHeading back......");
    sleep(2);
}

//!---------------------------------------------------------

void summary()
{
    star();
    printf("\n        *****ACCOUNT DETAILS*****\n");
    star();
    printf("\nName : %s\n", name);
    printf("Account No. : %d\n", acc_no);
    printf("Total balance = %d\n ", amt);

    printf("\n\nExiting.....");
    sleep(5);
    system("cls");

}
