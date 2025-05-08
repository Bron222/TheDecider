#include <iostream>
#include<cstdlib>
#include <string>
#include <windows.h>

using namespace std;

//-------------------------FUNCTION PROTOTYPES----------------------------------
void clearScreen(); //clears the screen
//------------------------------------------------------------------------------

int main()
{
	int random;
	string userInput = "yes";
	const int fulcrum = 51;
	string secondInput = "yes";
	string choice1;
	string choice2;
	

	
		do {
			
			//introduction

			clearScreen();

			cout << "Can't decide between two choices?" << "\n\n\n\n";
			cout << "...Allow The Decider to lend a hand..." << "\n\n\n\n\n";

			cout << "press enter to continue\n";
			cin.get();

			clearScreen();

			cout << "Enter choice number one: ";
			getline(cin, choice1);

			clearScreen();

			cout << "Enter choice number two: ";
			getline(cin, choice2);

			clearScreen();
			
			cout << "**You enter a dark room and eerie music plays as a shadowy figure emerges from the darkness**\n";
			cout << endl;
			cout << "press enter to continue\n";
			cin.get();

			clearScreen();

			cout << "\"You have entered the presence of The Decider...\" a deep voice says.\n";
			cout << endl;
			cout << "press enter to continue\n";
			cin.get();
			
			clearScreen();

			cout << "\"I will make any decision for you...\n...I only ask that you honor my judgement... \n";
			cout << "...or else doom will ensue you... \n";
			cout << endl;
			cout << "press enter to continue\n";
			cin.get();

			clearScreen();

			cout << "...now, think of two options in your mind...\"\n\n";
			cout << endl;
			cout << "press enter to continue\n";
			cin.get();

			clearScreen();

			
			cout << "**eerie music intensifies as the shadowy figure reaches out his boney hand** \n\n"
				<<"Do you promise to honor The Decider's final judgement between choice one and choice two?\n\n";

			//User enters their first response

			do
			{
				if (userInput != "yes" && userInput != "no") //input validation
				{
					clearScreen();

					cout << "Your errors will not be tolerated by The Decider.\n\n";


				}
				cout << "Type \"yes\" to shake the dark figure's hand. Otherwise, type \"no\".\n\n";
				cin >> userInput;

			} while (userInput != "yes" && userInput != "no"); //input validation loop


			/* Below is entering user's input against "if" statement, 
			
				then random # generator picks a number, then condition determines the choice */

			if (userInput == "yes")
			{
				srand((unsigned)time(NULL)); //random number generator 
				random = 1 + (rand() % 100); //set between 1-100

				if (random >= fulcrum) //OPTION 1 for Decider's choice.
				{
					
					clearScreen();

					cout << "\n\n...your fate has been decided...\n\n...\n";
						cout << endl;
					cout << "press enter to continue\n";
					cin.get();
					
					clearScreen();

					cout << "...a cold creeps up your spine...\n";
					cout << endl;
					cout << "press enter to continue\n";
					cin.get();

					clearScreen();

					cout<< "...The Decider has chosen...\n\n";
					cout << endl;
					cout << "press enter to reveal your fate\n";
					cin.get();

					clearScreen();

					cout << choice1 << "!\n\n\n\n";

					cout <<"...the figure screeches with maniacal laughter and fades back into the darkness...\n\n\n\n\n\n";
						
				}
				if (random < fulcrum) //OPTION 2 for Decider's choice.
				{
					clearScreen();

					cout << "\n\n...your fate has been decided...\n";
					cout << endl;
					cout << "press enter to continue\n";
					cin.get();

					clearScreen();

			
					cout << "...a cold creeps up your spine...\n";
					cout << endl;
					cout << "press enter to continue\n";
					cin.get();

					clearScreen();

						cout << "The Decider has chosen...\n\n";
						cout << endl;
						cout << "press enter to reveal your fate\n";
						cin.get();

						clearScreen();

						cout << choice2 << "!\n\n\n\n";

						cout <<"...the figure screeches with maniacal laughter as he fades back into the darkness...\n\n\n\n\n";
						
				}

			}
			else //result of not shaking Decider's hand
			{
				clearScreen();

				cout << "\n\nThe shadowy figure suddenly appears behind you and pulls you into the darkness...\n\n\n\n" 
					<< "...You were never heard from again...\n\n\n\n\n";
			}
			
				//"play again" sequence

			do  
			{
				if (secondInput != "yes" && secondInput != "no") //input validation
				{
					clearScreen();

					cout << "Your errors anger The Decider. He doesn't like your games.\n\n";
				}
				cout << "Would you like to play again? Enter \"yes\" or \"no\"\n\n";
				cin >> secondInput;
				cout << endl << endl << endl;

			} while (secondInput != "yes" && secondInput != "no"); //input validation loop

		} while (secondInput == "yes"); //the "play again" loop

	return 1;
}
//=========================FUNTION DEFINITIONS==================================
//==============================================================================
void clearScreen()
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}