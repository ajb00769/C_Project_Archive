#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define HOUR 3600
#define MAX_EMPLOYEES 5000

typedef struct employee_data
{
    char employee_num[4];
    char last_name[20];
    char first_name[20];
    char middle_name[20];
    unsigned int hourly_rate;
    int accrued_hours;
    int current_payout;
};

int home_page(int choice, int err_chk);
int calculate_salary(int employee_id, int hours_rendered, int bonus);
void new_employee();
void existing_employee();

int main(void)
{
    unsigned int option_selected;
    printf("\nWelcome to Allen's Employee Databasing Program :)\n\nSelect an option:\n1. New Employee\n2. Get Existing Employee Data\n3. Calculate Employee Salary\n");
    scanf("%d", &option_selected);
    int next_step = home_page(option_selected, 0);
    return 0;

    FILE *fptr;
    fptr = fopen("database.csv", "w+");

    if (fptr == NULL)
    {
        printf("ERROR.\n");
		exit(EXIT_FAILURE);
    }
    else
    {
        fread();
    }
}

int home_page(int choice, int err_chk)
{
    if (err_chk == 0)
    {
        if (choice == 1)
        {
            //new_employee();
            printf("test success choice made is: %d", choice);
            return 0;
        }
        else if (choice == 2)
        {
            //existing_employee();
            printf("test success choice made is: %d", choice);
            return 0;
        }
        else if (choice == 3)
        {
            //calculate_salary();
            printf("test success choice made is: %d", choice);
            return 0;
        }
        else
        {
            printf("Invalid entry. Please choose again: ");
            home_page(choice, 1);
        }
    }
    else if (err_chk != 0)
    {
        scanf("%d", &choice);
        home_page(choice, 0);
    }
    return 0;
}

void new_employee()
{
    int x = 0;

    for (int i = 0; i < MAX_EMPLOYEES; i++)
    {

    }

    printf("Last Name: ");
    scanf("%s", &employee_data[x].employee_name);
    printf("First Name: ");
    printf("Middle Name: ");
    printf("Hourly Rate: ");
}