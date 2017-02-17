#include "MainClass.h"



MainClass::MainClass()
{
}


MainClass::~MainClass()
{
}

#include <iostream>
using namespace std;

const int letters = 26;   //An array of 26 for 26 letters of the alphabet

void recordAndCount(char listarray[], int counterarray[], char input);
void answerDisplay(char listarray[], int counterarray[]);

int main()
{
	char letterListArray[letters];   //This array records the letters typed by the user.
	int letterCounterArray[letters]; //This array is for counting the letters entered.
	for (int i = 0; i < 26; i++) //Creates a value for each character of the array.
	{
		letterCounterArray[i] = 0;
		letterListArray[i] = '0';  //Note: Since letterListArray is a char, 0 must be a character here.
	}								//It doesn't need to be '0', but it must be a digit.
	char input;

	while (true)
	{
		cout << "Enter some letters, then type a digit to finish.\n";
		cin >> input;
		if (isalpha(input) > 0) //Sends any letters to the listing/counting function.
		{
			input = tolower(input);
			recordAndCount(letterListArray, letterCounterArray, input);
		}
		if (isdigit(input) > 0)  //Checks if the user wants to see their results.
		{
			cout << "\nDisplaying answer:\n";
			answerDisplay(letterListArray, letterCounterArray);
			cout << "\nWould you like to type more letters? (y/n)\n";
			cin >> input;
			if (input == 'y') //If 'y' is typed, continue. If anything but 'y' is typed, end the program.
			{
				cout << "Would you like to reset the count? (y/n)\n";
				cin >> input;
				if (input == 'y') //If 'y' is not typed, program goes back to loop start with current letter count.
				{
					for (int i = 0; i < 26; i++) //If 'y' is typed, reset arrays.
					{
						letterCounterArray[i] = 0;
						letterListArray[i] = '0';
					}
				}
			}
			else
			{
				return 0;
			}
		}

	}
}

void recordAndCount(char listarray[], int counterarray[], char input)  //Records new letters in the list array and counts how many times they've been typed.
{
	for (int i = 0; i < 26; i++)
	{
		if (isalpha(listarray[i]) > 0 && listarray[i] == input)  //if it finds the input letter has been typed before, adds one to its count and ends function.
		{
			counterarray[i]++;
			break;
		}
		if (isdigit(listarray[i]) > 0) //If the letter has never been typed before, list it in the array and add one to count. Then end function.
		{
			listarray[i] = input;
			counterarray[i]++;
			break;
		}
	}
}

void answerDisplay(char listarray[], int counterarray[])
{
	for (int i = 0; i < 26; i++)
	{
		if (isalpha(listarray[i]) > 0)   //If it finds a letter, displays its related count.
		{
			cout << listarray[i] << " " << counterarray[i] << endl;
		}
	}
}
