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
int choice_page(int choice);
void new_employee(void);
void get_employee(void);
void calc_salary(void);
void input_salary(void);
void save_struct(void);
void read_data(void);

int main(void)
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
    
    while(exit)
    {
        read_data();
        home();
        save_struct();
    }
}

int home(void)
{
    //printf("\nWelcome to Allen's Employee Databasing Project :)\n\nSelect an option:\n1. New Employee\n2. Get Existing Employee Data\n3. Calculate Employee Salary\n4. Exit\n");
    printf("                 /           /\n                /' .,,,,  ./\n               /';'     ,/\n              / /   ,,//,`'`\n             ( ,, '_,  ,,,' ``\n             |    /@  ,,, ;' `\n            /    .   ,''/' `,``\n           /   .     ./, `,, ` ;\n        ,./  .   ,-,',` ,,/''|,'\n       |   /; ./,,'`,,'' |   |\n       |     /   ','    /    |\n        |___/'   '     |     |\n          `,,'  |      /     `\nElvarg's       /      |        ~\n HR Database  '       (\n  Program    :\n            ; .         |--\nBy Allen  :   |         ;\n\nSelect an option:\n1. New Employee\n2. Get Existing Employee Data\n3. Calculate Employee Salary\n4. Add/Modify Employee Salary\n5. Exit\n\n");

    int option_selected;

    printf("Enter Number of Choice: ");

    scanf("%d", &option_selected);
    getchar();
    choice_page(option_selected);

    return 0;
}

int choice_page(int choice)
{
    if (choice == 1)
    {
        new_employee();
    }
    else if (choice == 2)
    {
        get_employee();
    }
    else if (choice == 3)
    {
        calc_salary();
    }
    else if (choice == 4)
    {
        input_salary();
    }
    else if (choice == 5)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Invalid Choice. Please choose again.\n");
    }
}

void new_employee(void)
{
    printf("***NEW EMPLOYEE REGISTRATION***\n");

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {
        if (newcorp[i].occupied_status == false)
        {
            while(!isalpha(*newcorp[i].last_name) && strlen(newcorp[i].last_name) < MAX_NAME_SIZE)
            {
                printf("Last Name: ");
                fgets(newcorp[i].last_name, sizeof(newcorp[i].last_name), stdin);
                
                if(islower(newcorp[i].last_name[1]))
                {
                    toupper(newcorp[i].last_name[1]);
                }
            }
            
            while(!isalpha(*newcorp[i].first_name) && strlen(newcorp[i].first_name) < MAX_NAME_SIZE)
            {
                printf("First Name: ");
                fgets(newcorp[i].first_name, sizeof(newcorp[i].first_name), stdin);
            }

            while(!isalpha(*newcorp[i].middle_name) && strlen(newcorp[i].middle_name) < MAX_NAME_SIZE)
            {
                printf("Middle Name: ");
                fgets(newcorp[i].middle_name, sizeof(newcorp[i].middle_name), stdin);
            }

            printf("\n***Employee Registration SUCCESS***\n\n");
            printf("Employee No.: \t%d\n", newcorp[i].employee_num);
            printf("Last Name: \t%s", newcorp[i].last_name);
            printf("First Name: \t%s", newcorp[i].first_name);
            printf("Middle Name: \t%s", newcorp[i].middle_name);
            printf("Hourly Wage: \t$%.2f\n", newcorp[i].hourly_rate);

            newcorp[i].occupied_status = true;
                    
            system("pause");
            break;
        }
    }
}

void get_employee(void)
{
    int choice;

    printf("***Find Employee Details***\nSearch By:\n1. Employee Number\n2. Employee First Name\n3. Employee Last Name\nPlease Enter Your Choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int x;
        printf("Please Enter The Employee Number: ");
        scanf("%d", &x);

        if (newcorp[x].occupied_status == true)
        {
            printf("Employee Number: %d\n", newcorp[x].employee_num);
            printf("Name: %s, %s %s\n", newcorp[x].last_name, newcorp[x].first_name, newcorp[x].middle_name);
            printf("Hourly Pay: $%.2f\n", newcorp[x].hourly_rate);
            printf("Hours Worked: %d Hrs. \n",newcorp[x].accrued_hours);
            printf("Salary Last Received: $%.2f\n", newcorp[x].current_payout);
        }
        else
        {
            printf("No Employee Registered with that Employee Number.\n");
        }
    }

    if (choice == 2)
    {
        char fname[MAX_NAME_SIZE];
        printf("What is the Employee's First Name? ");
        getchar();
        fgets(fname, sizeof(fname), stdin);

        for (int i = 0; i < MAX_EMPLOYEES; i++)
        {
            if (newcorp[i].occupied_status == true)
            {
                while (strcasecmp(fname, newcorp[i].first_name) == 0)
                {
                    printf("Employee Number: %d\n", newcorp[i].employee_num);
                    printf("Name: %s, %s %s\n", newcorp[i].last_name, newcorp[i].first_name, newcorp[i].middle_name);
                    printf("Hourly Pay: $%f\n", newcorp[i].hourly_rate);
                    printf("Hours Worked: %d Hrs. \n",newcorp[i].accrued_hours);
                    printf("Salary Last Received: $%.2f\n", newcorp[i].current_payout);

                    break;
                }
            }
        }
        printf("Could not find Employee.\n");
    }

    if (choice == 3)
    {
        char lstname[MAX_NAME_SIZE];
        printf("What is the Employee's Last Name? ");
        getchar();
        fgets(lstname, sizeof(lstname), stdin);

        for (int i = 0; i < MAX_EMPLOYEES; i++)
        {
            if (newcorp[i].occupied_status == true)
            {
                while (strcasecmp(lstname, newcorp[i].last_name) == 0)
                {
                    printf("Employee Number: %d\n", newcorp[i].employee_num);
                    printf("Name: %s, %s %s\n", newcorp[i].last_name, newcorp[i].first_name, newcorp[i].middle_name);
                    printf("Hourly Pay: $%.2f\n", newcorp[i].hourly_rate);
                    printf("Hours Worked: %d Hrs. \n",newcorp[i].accrued_hours);
                    printf("Salary Last Received: $%.2f\n", newcorp[i].current_payout);

                    break;
                }
            }
        }
        printf("Could not find Employee.\n");
    }
    system("pause");
}

void input_salary(void)
{
    int empnumber;

    printf("***INPUT/MODIFY Employee Salary***\nPlease Enter Employee Number: ");
    scanf("%d", &empnumber);

    if (newcorp[empnumber].occupied_status == true)
    {
        int old_salary = newcorp[empnumber].hourly_rate;

        printf("Enter Employee Hourly Rate: $");
        scanf("%f", &newcorp[empnumber].hourly_rate);
        if (old_salary != newcorp[empnumber].hourly_rate)
        {
            printf("Salary change SUCCESS.\n");
            system("pause");
        }
        else
        {
            printf("Salary not modified.\n");
            system("pause");
        }
    }
    else
    {
        printf("Employee not found.");
        system("pause");
    }
}

void calc_salary(void)
{
    int empNo;
    printf("Please enter employee number to calculate salary: \n");
    scanf("%d", &empNo);

    if (newcorp[empNo].occupied_status == true)
    {
        printf("Enter Hours Rendered: ");
        scanf("%d", &newcorp[empNo].accrued_hours);
        newcorp[empNo].current_payout = newcorp[empNo].accrued_hours * newcorp[empNo].hourly_rate;
        printf("%s, %s %s salary: $%.2f\n", newcorp[empNo].last_name, newcorp[empNo].first_name, newcorp[empNo].middle_name, newcorp[empNo].current_payout);
    }
    else
    {
        printf("Employee does not exist.");
    }
    system("pause");
}

void save_struct(void)
{
    FILE *fname;
    fname = fopen("database.bin", "w");
    fwrite(&newcorp, sizeof(employee_data), MAX_EMPLOYEES, fname);
    fclose(fname);
}

void read_data(void)
{
    FILE *fname;
    fname = fopen("database.bin", "r");
    fread(&newcorp, sizeof(employee_data), MAX_EMPLOYEES, fname);
    fclose(fname);
}