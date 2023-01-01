#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randPass(int inp);
void foutput(char *input);

int main()
{
		int desiredLength = 0;
		printf("Hi, Welcome to my Random Password Generator.\nPlease enter the desired length for your password: ");
		scanf("%d", &desiredLength);

		if (desiredLength > 20)
		{
				printf("password_length cannot exceed 20 characters.\n");
				return 1;
		}

		randPass(desiredLength);
		fopen("newpass.txt", "r");
		system("pause");
		return 0;
}

void randPass(int inp)
{
		int randomizer = 0;

		srand(time(0));

		char numbers[] = "0123456789";
		char letter[] = "abcdefghijklmnoqprstuvwyzx";
		char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
		char symbols[] = "!@#$%^&*";
		char password[20];
		randomizer = rand() % 4;

		for (int i = 0; i < inp; i++)
		{
				if (randomizer == 1)
				{
						password[i] = numbers[rand() % 10];
				}
				else if (randomizer == 2)
				{
						password[i] = symbols[rand() % 8];
				}
				else if (randomizer == 3)
				{
						password[i] = LETTER[rand() % 26];
				}
				else
				{
						password[i] = letter[rand() % 26];
				}
				randomizer = rand() % 4;
		}
		foutput(password);
		return;
}

void foutput(char *input)
{
		FILE *fPtr;
		fPtr = fopen("newpass.txt", "w");

		if (fPtr == NULL)
		{
				printf("ERROR.\n");
				exit(EXIT_FAILURE);
		}

		fprintf(fPtr, "%s", input);
		fclose(fPtr);
		printf("Password generated successfully. Open newpass.txt to see your randomly generated password.\n");

		return;
}