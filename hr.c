#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define HOUR 3600
#define MAX_EMPLOYEES 5000
#define MAX_NAME_SIZE 20

typedef struct
{
    bool occupied_status;
    unsigned int employee_num;
    char last_name[MAX_NAME_SIZE];
    char first_name[MAX_NAME_SIZE];
    char middle_name[MAX_NAME_SIZE];
    float hourly_rate;
    int accrued_hours;
    float current_payout;
}
employee_data;

employee_data newcorp[MAX_EMPLOYEES];

int home(void);
int first_page(int choice, int err_chk);

int main(void)
{
    FILE *fname;
    fname = fopen("database.txt", "w+");

    if (fname == NULL)
    {
        printf("ERROR.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        //populate the database with an array of candidates
        for (int i = 0; i < MAX_EMPLOYEES; i++)
        {
            newcorp[i].occupied_status = false;
            newcorp[i].employee_num = i;
            newcorp[i].hourly_rate = 0;
            newcorp[i].accrued_hours = 0;
            newcorp[i].current_payout = 0;
        }
    }
    
    while(exit)
    {
        home();
    }
}

int home(void)
{
    int option_selected;

    //printf("\nWelcome to Allen's Employee Databasing Project :)\n\nSelect an option:\n1. New Employee\n2. Get Existing Employee Data\n3. Calculate Employee Salary\n4. Exit\n");
    printf("                 /           /\n                /' .,,,,  ./\n               /';'     ,/\n              / /   ,,//,`'`\n             ( ,, '_,  ,,,' ``\n             |    /@  ,,, ;' `\n            /    .   ,''/' `,``\n           /   .     ./, `,, ` ;\n        ,./  .   ,-,',` ,,/''|,'\n       |   /; ./,,'`,,'' |   |\n       |     /   ','    /    |\n        |___/'   '     |     |\n          `,,'  |      /     `\nElvarg's       /      |        ~\n HR Database  '       (\n  Program    :\n            ; .         |--\nBy Allen  :   |         ;\n\n");
    printf("Choice: ");

    scanf("%d", &option_selected);
    getchar();

    int status_chk = first_page(option_selected, 0);

    return status_chk;
}

int first_page(int choice, int err_chk)
{
    if (err_chk == 0)
    {
        if (choice == 1)
        {
            printf("test success choice made is: %d", choice);
        }
        else if (choice == 2)
        {
            //existing_employee();
            printf("test success choice made is: %d", choice);
        }
        else if (choice == 3)
        {
            //calculate_salary();
            printf("test success choice made is: %d", choice);
        }
        else if (choice == 4)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("\nInvalid entry. Please choose again.\n");
            system("pause");
        }
    }
    return 0;
}